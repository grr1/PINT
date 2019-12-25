#include "pint.h"

namespace pint
{
  NonSequentialNet::NonSequentialNet()
  {
    this->numLayers = 0;
    this->in = new ReflexivityNode();
  }

  NonSequentialNet::~NonSequentialNet()
  {
    //TODO: Delete all the opnodes and weights.
  }

  void NonSequentialNet::addLayer(int inSize, int outSize, std::string currLayerName, std::string inLayerName)
  {
    // Checking layer names
    if (layerNames.find(currLayerName) != layerNames.end())
    {
      // TODO would be nice to have a unified error message format, maybe something to put in the coding styles doc instead
//      fprintf(stderr, "addLayer: the layer name " + currLayerName + " has already been used for a previous layer in this network\n");
      exit(1);
    }
    if (layerNames.find(inLayerName) == layerNames.end() && inLayerName != "") // first layer gets a free pass
    {
//      fprintf(stderr, "addLayer: the layer name " + inLayerName + " has not been used before, so it cannot be used as an input for " + currLayerName + "\n");
      exit(1);
    }
    layerNames.insert(currLayerName);

    // Grabbing nodes from previous layer
    OpNode* prevSigNode = this->opNames[inLayerName + "_a"];

    // Make new weight matrix
    int wShape[2] = {outSize, inSize};
    PTensor* w = new PTensor(randpt(2, wShape));
    this->weights.push_back(w);

    // Make new weight reflex node
    ReflexivityNode* weightNode = new ReflexivityNode();
    weightNode->setTensor(w);
    this->opNames[currLayerName + "_w"] = weightNode;

    // Set parents for dot product
    std::vector<OpNode*> parentList;
    parentList.push_back(weightNode); // we push weights first for W*x = b
    if (inLayerName != "") {
      parentList.push_back(prevSigNode); // where out is x
    } else {
      parentList.push_back(this->in); // input of the network if this is the first layer being added
    }
    DotProductNode * dotNode = new DotProductNode(parentList);   //NOTE/TODO: This is assuming that the first arg of the new version is a parent vector.
    this->opNames[currLayerName + "_d"] = dotNode;

    // Set activation node's parents
    parentList.clear(); // can use same vector TODO is this preferable
    parentList.push_back(dotNode);
    SigmoidNode * sigNode = new SigmoidNode(parentList);
    this->opNames[currLayerName + "_a"] = sigNode;
    this->numLayers++;
  }

  PTensor NonSequentialNet::run(PTensor * input, std::string layer)
  {
    ((ReflexivityNode*)(this->in))->setTensor(input); // TODO: is this how to properly maintain a vector of abstracts?
    return this->opNames[layer+"_a"]->eval();   //NOTE/TODO: I assume this is how it's supposed to work, but please check.
  }

}
