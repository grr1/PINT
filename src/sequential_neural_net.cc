
#include "pint.h"


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
    this->out = sigNode;
    this->numLayers++;
  }

  PTensor SequentialNet::run(PTensor * input)
  {
    ((ReflexivityNode*)(this->in))->setTensor(input); // TODO: is this how to properly maintain a vector of abstracts?
    return this->out->eval();   //NOTE: I assume this is how it's supposed to work, but please check.
  }

}
