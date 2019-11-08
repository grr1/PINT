// TODO: implement opnode to contain compute/derivative and parent opnodes
#ifndef OPNODE_H
#define OPNODE_H

#include "pint.h"

using namespace std;

namespace pint
{

class OpNode
{
private:
    vector<OpNode*> *parents;
    PTensor _result;
    bool _set = false;

    virtual PTensor compute(PTensor, PTensor)=0; // takes input val
    virtual PTensor derivative(PTensor, PTensor)=0; // takes result to act on derivate

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
