#ifndef SANN_H
#define SANN_H

#include "pint.h"

using namespace std;
namespace pint
{

class SequentialNet
{
private:
    ReflexivityNode * in;
    OpNode * out;
    int numLayers;
    
public:
    PTensor * prevLayerDelta;
    SequentialNet();
    ~SequentialNet();
    vector<PTensor*> weights; // TODO: this should be private, but it can't right now
    vector<SigmoidNode*> layerOuts;
    vector<PTensor*> layerAdjustments;
    void addLayer(int inSize, int outSize);
    PTensor run(PTensor * input);
    vector<PTensor*> backwardProp(PTensor * trueOutput);
};

}

#endif
