#ifndef OPNODE_H
#define OPNODE_H

#include "pint.h"

using namespace std;

namespace pint
{

class OpNode
{
private:
    vector<OpNode *> _parents;
    PTensor _result;
    //bool _set = false;

    virtual PTensor compute(vector<PTensor> args) = 0; // takes input tensors
    //virtual PTensor derivative(PTensor, PTensor)=0; // takes result to act on derivate

public:

    OpNode();
    OpNode(vector<OpNode *> parents);
    ~OpNode();

    PTensor eval();

    // TODO: addParent methods

    //void setResult(PTensor);
    //PTensor getResult();
    //PTensor unsetResult();

};

}

#endif
