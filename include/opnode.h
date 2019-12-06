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
    //bool _set = false;

    virtual PTensor compute(vector<PTensor*>) = 0; // takes input tensors

public:
    PTensor * _result; // TODO: shouldn't be public, but has to be right now

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
