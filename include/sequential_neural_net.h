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

    SequentialNet();
    ~SequentialNet();

    void addLayer(int inSize, int outSize);
    PTensor run(PTensor * input);
    vector<PTensor*> backwardProp(PTensor * expectedOutput, double lr=0.02);
<<<<<<< HEAD
    void save(char* filepath);
    void load(char* filepath);
=======
    void basicTrain(vector<PTensor*>, vector<PTensor*>, int epochs=1, double lr=0.02);

    // TODO: implement actual epochs with batching; may need ptensor vector dimensioning
>>>>>>> 6c708ac48e72c3bb7076d24015cc0d806a4ab957
};

}

#endif
