
#include "pint.h"
#include <iostream>
#include <algorithm>
#include "ptensor.h"
namespace pint
{

  SequentialNet::SequentialNet()
  {
    this->numLayers = 0;
    this->in = new ReflexivityNode();
    this->out = this->in;
  }

  SequentialNet::~SequentialNet()
  {
    //TODO: Delete all the opnodes and weights.
  }

  void SequentialNet::addLayer(int inSize, int outSize)
  {
    // Make new weight matrix
    int wshape[2];
    wshape[0] = outSize;
    wshape[1] = inSize;
    PTensor * w = new PTensor(randpt(2, wshape));
    weights.push_back(w);

    // Make new weight reflex node
    ReflexivityNode * weightNode = new ReflexivityNode();
    weightNode->setTensor(w);

    // Set parents for dot product
    std::vector<OpNode*> parentList;
    parentList.push_back(weightNode); // we push weights first for W*x = b
    parentList.push_back(this->out); // where out is x
    DotProductNode * dotNode = new DotProductNode(parentList);   //NOTE: This is assuming that the first arg of the new version is a parent vector.

    parentList.clear();

    parentList.push_back(dotNode);
    SigmoidNode * sigNode = new SigmoidNode(parentList);

    layerOuts.push_back(sigNode);
    this->out = sigNode;
    this->numLayers++;
  }

  PTensor SequentialNet::run(PTensor * input)
  {
    this->in->setTensor(input);
    return this->out->eval();   //NOTE: I assume this is how it's supposed to work, but please check.
  }

  vector<PTensor*> SequentialNet::backwardProp(PTensor* trueOutput)
  {
    //Transpose(prevOutput) DOT (LayerError * F'(currOutput)) 
    //LayerError = PrevLayerDelta DOT Transpose(Weights)
    //LayerError for output will be set to MSE (y - output)
    PTensor* weightUpdate = new PTensor();
    PTensor* currentLayerDelta = new PTensor();
    PTensor* currentLayerError = new PTensor();
    PTensor* prevLayerDelta = new PTensor();
    for (int i = weights.size()-1; i >= 0; i--)
    {
        printf("%d\n",i);
      if (i == weights.size()-1)
      {
        *currentLayerError = *trueOutput - *(layerOuts[i]->_result);
      }
      else
      {
        *currentLayerError = mult(*prevLayerDelta, *weights[i+1]); //
      }
        printf("delta\n");
        printPTensor(*currentLayerError);
        printPTensor(layerOuts[i]->derivate(*(layerOuts[i]->_result)));
      *currentLayerDelta = *currentLayerError * layerOuts[i]->derivate(*(layerOuts[i]->_result));
        printPTensor(*currentLayerDelta);
        printf("weightUpdate\n");
        printPTensor(*weights[i]);
      *weightUpdate = mult(*currentLayerDelta, *weights[i]); //
        printf("layerAdjustment\n");
        printPTensor(*weightUpdate);
      layerAdjustments.push_back(weightUpdate);
        printf("prevDelta\n");
      *prevLayerDelta = *currentLayerDelta;
        printPTensor(*prevLayerDelta);
    }
    reverse(layerAdjustments.begin(),layerAdjustments.end());
   
    printf("update\n"); 
    for (int i = 0; i < weights.size(); i++)
    {
        *weights[i] += *layerAdjustments[i];
    }

    return layerAdjustments;
  }
}
