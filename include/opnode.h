//TODO: how are these supposed to be used? One per layer or multiple?

#ifndef OPNODE_H
#define OPNODE_H

#include "pint.h"

using namespace std;

namespace pint
{

class OpNode
{
private:
    PTensor _weights;
    PTensor _result; // TODO: store as pointer for easier passing?
    bool _set = false;

    virtual PTensor compute(PTensor, PTensor)=0; // takes input val
    virtual PTensor derivative(PTensor)=0; // takes result to act on derivate

public:
    OpNode* left_parent;
    OpNode* right_parent;

    OpNode(OpNode*, OpNode*);
    ~OpNode();

    PTensor eval();

    void setResult(PTensor);
    PTensor getResult();
    PTensor unsetResult();

};

}

#endif
