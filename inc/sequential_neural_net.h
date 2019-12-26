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
    vector<PTensor*> weights; // TODO: this should be private, but it can't right now
    vector<SigmoidNode*> layerOuts;
    vector<PTensor*> layerDeltas;
    vector<PTensor*> layerAdjustments;

    SequentialNet();
    ~SequentialNet();

    void addLayer(int inSize, int outSize, int nColor=1);
    PTensor run(PTensor * input);
    vector<PTensor*> backwardProp(PTensor * expectedOutput, double lr=0.02);
    void train(PTensor*, PTensor*, int epochs=1, int mbs=0, double lr=0.02);

    void save(char* filepath);
    void load(char* filepath);
};

}

#endif
