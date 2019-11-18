

#ifndef SANN_H
#define SANN_H

#include <vector>
using namespace std;
namespace pint
{
  class SequentialNet
  {
    private:
      OpNode * in;
      OpNode * out;
      int numLayers;

    public:
      SequentialNet();
      ~SequentialNet();
      vector<PTensor*> weights; // TODO: this should be private, but it can't right now
      vector<PTensor*> layerOutputs;
      vector<PTensor*> layerAdjustments:
      PTensor* prevLayerDelta;
      void addLayer(int inSize, int outSize);
      PTensor run(PTensor * input);
      vector<PTensor*> backwardProp();
  };
}


#endif
