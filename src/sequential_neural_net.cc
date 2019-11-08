
#include "pint.h"


namespace pint
{

  SequentialNet::SequentialNet()
  {
    this->numLayers = 0;
    this->in = new ReflexvityNode();
    this->out = this->in;
    this->weights = new std::vector<PTensor*>()
  }

  SequentialNet::~SequentialNet()
  {
    //TODO: Delete all the opnodes and weights.
  }

  void SequentialNet::addLayer(int inSize, int outSize)
  {
    //TODO: Add a new randomized weight ptensor of shape inSize x outSize.
    std::vector<OpNode*> parentList;
    parentList.push_back(this->out);
    OpNode * weightNode = new ReflexvityNode();
    parentList.push_back(weightNode);   //TODO: Tie this to the layer's weight ptensor.
    OpNode * dotNode = new DotProductNode(parentList);   //NOTE: This is assuming that the first arg of the new version is a parent vector.
    parentList.clear();
    parentList.push_back(dotNode);
    OpNode * sigNode = new SigmoidNode(parentList);   //TODO: Add the sigmoid node.
    this->out = sigNode;
    this->numLayers++;
  }

  PTensor * SequentialNet::run(PTensor * input)
  {
    this->in->setTensor(input);
    return this->out->eval();   //NOTE: I assume this is how it's supposed to work, but please check.
  }

}
