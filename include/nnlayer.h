// TODO: implement nnlayer to contain weight and result
// ToDO: do we really need this? It's just handling opnodes
#ifndef NNLAYER_H
#define NNLAYER_H

#include "pint.h"

using namespace std;

namespace pint
{

class NNLayer
{
private:
    PTensor _weights;
    PTensor _result;
    bool _set = false;

public:
    NNLayer(OpNode*, OpNode*);
    ~NNLayer();

    PTensor eval();

    void setResult(PTensor);
    PTensor getResult();
    PTensor unsetResult();
};

}

#endif
