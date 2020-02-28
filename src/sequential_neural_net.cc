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

<<<<<<< HEAD
  vector<PTensor*> SequentialNet::backwardProp(PTensor * expectedOutput, double lr)
  {

=======
vector<PTensor*> SequentialNet::backwardProp(PTensor * expectedOutput, double lr)
{
    
>>>>>>> 6c708ac48e72c3bb7076d24015cc0d806a4ab957
    /*
        Example: 784 -> 512 -> 10
        W_1                             512x784         (784, 512)
        W_2                             10x512          (512, 10)

        X                               784x100         (100, 784)
        U                               512x100         (100, 512)
        Y                               10x100          (100, 10)
        V                               10x100          (100, 10)

        L2e = MSE'(Y,V) = Y - V         10x100          (100, 10)
        L2d = L2e * f'(V)               10x100          (100, 10)

        L1e = Transpose(W_2) DOT L2d    512x100         (100, 512)
        L1d = L1e * f'(U)               512x100         (100, 512)

        L1a = L1d DOT Transpose(X)      512x784         (784, 512)
        L2a = L2d DOT Tranpose(U)       10x512          (784, 512)
    */

    PTensor y = *expectedOutput;
    PTensor x = *(in->_result);
    PTensor l1e;
    PTensor l1d;
    PTensor l1a;
    PTensor l2d;
    PTensor v;
    vector<PTensor*> ld;
    vector<PTensor*> la;

    //printf("error and deltas\n");
    for (int i = numLayers-1; i >= 0; i--)
    {
        //printf("%d\n",i);
        v = *(layerOuts[i]->_result);
        //printf("le\n");
        if (i == numLayers-1)
        {
            l1e = y - v;
        }
        else
        {
            l1e = mult(weights[i+1]->transpose(), l2d);
        }
        //printPTensor(l1e);
        //printf("ld\n");
        l1d = l1e * layerOuts[i]->derivate(v);
        //printPTensor(l1d);
        //printf("push ld\n");
        ld.push_back(new PTensor(l1d));
        //printf("set next\n");
        l2d = l1d;
    }

    reverse(ld.begin(), ld.end());

    //printf("adjustments\n");
    for (int i = 0; i < numLayers; i++)
    {
        //printf("%d\n", i);
        if (i == 0)
        {
            l1a = mult(*ld[i], x.transpose());
        }
        else
        {
            l1a = mult(*ld[i], layerOuts[i-1]->_result->transpose());
        }
        //printPTensor(l1a);
        la.push_back(new PTensor(l1a));
    }
<<<<<<< HEAD

    printf("update\n");
=======
    
    //printf("update\n"); 
>>>>>>> 6c708ac48e72c3bb7076d24015cc0d806a4ab957
    for (int i = 0; i < weights.size(); i++)
    {
        //printf("%d\n",i);
        //printPTensor(*weights[i]);
        //printPTensor(*la[i]);
        *weights[i] += *la[i] * lr;
    }

    return la;
<<<<<<< HEAD
  }

  void SequentialNet::save(char* filepath)
  {
    // filepath checking
    std::ofstream outFile;
    outFile.open(filepath, std::ios::trunc); // TODO should there be a "verbose" mode that asks users if they would like to overwrite an existing file
    if (outFile.fail()) {
        fprintf(stderr, "Error: could not open file %s", filepath);
        exit(1);
    }

    // creating JSON format
    std::string out = "{\n"
        "\ttype: \"sequential_net\","
        "\t


  }

  void SequentialNet::load(char* filepath)
  {
    // filepath checking
    std::ifstream inFile;
    inFile.open(filepath, std::ios::in);
    if (inFile.fail()) {
        fprintf(stderr, "Error: could not open file %s\n", filepath);
        exit(1);
    }

    // harvesting JSON format
=======
}

void SequentialNet::basicTrain(vector<PTensor*> inputs, vector<PTensor*> expectedOutputs, int epochs, double lr)
{
    if (inputs.size() != expectedOutputs.size())
    {
        printf("Different inputs and expectedOutputs vector sizes\n");
        exit(1);
    }

    for (int e = 0; e < epochs; e++)
    {
        printf("epoch:\t%d\r", e);
        for (int i = 0; i < inputs.size(); i++)
        {
            this->run(inputs[i]);
            this->backwardProp(expectedOutputs[i]);
        }
    }
}
>>>>>>> 6c708ac48e72c3bb7076d24015cc0d806a4ab957
    
}
