#ifndef NSANN_H
#define NSANN_H

#include <vector>
#include <map>
#include <set>

namespace pint
{
  class NonSequentialNet
  {
    private:
      void removeNode(OpNode* n); // TODO would there be any case where a user would want a PUBLIC removeLayer to use during runtime
      int numLayers;
      OpNode * in;
      std::map<std::string, OpNode*> opNames; // _w for weights node, _a for activation node
      std::set<std::string> layerNames;

    public:
      NonSequentialNet();
      ~NonSequentialNet();
      std::vector<PTensor*> weights; // TODO: this should be private, but it can't right now
      void addLayer(int inSize, int outSize, std::string currLayerName, std::string inLayerName="");
      PTensor run(PTensor * input, std::string layer);
  };
}

#endif
