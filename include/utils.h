#ifndef UTILS_H
#define UTILS_H

#include "pint.h"

namespace pint
{

int init();

ostream & operator<<(ostream &os, const PTensor &t);
ostream & operator<<(ostream &os, const vector<PTensor*> &w);

// TODO: debug print and error print utils

class ReflexivityNode: public OpNode
{
using OpNode::OpNode;   
private:
    PTensor* tensor;

    // TODO: better way to handle variable number of parents for compute without going overboard?
    PTensor compute(vector<PTensor*> inp)
    {
        //printf("reflex comp\n");
        return *tensor;
    }

public:
    void setTensor(PTensor* inputTensor) { this->tensor = inputTensor; }

};

class DotProductNode: public OpNode
{
using OpNode::OpNode;
private:
    PTensor compute(vector<PTensor*> inp)
    {
        //printf("dot comp\n");
        PTensor w = *(inp[0]);
        PTensor x = *(inp[1]);

        return dot(w, x);
    }

};

class SigmoidNode: public OpNode
{
using OpNode::OpNode;
public:
    PTensor derivate(const PTensor &sig)
    {
        return sig*(1-sig);
    }
private:
    PTensor compute(vector<PTensor*> inp)
    {
        //printf("sig comp\n");
        PTensor x = *(inp[0]);

        return 1 / (1 + pint::exp(-x));
    }
};

}

#endif
