#ifndef UTILS_H
#define UTILS_H

#include "pint.h"

namespace pint
{

int init();

class ReflexivityNode: public OpNode
{   
private:
    PTensor* tensor;

    // TODO: better way to handle variable number of parents for compute without going overboard?
    PTensor compute(vector<PTensor> inp)
    {

        return *tensor;
    }

public:
    void setTensor (PTensor* inputTensor) { this->tensor = inputTensor; }

};

class DotProductNode: public OpNode
{
private:
    PTensor compute(vector<PTensor> inp)
    {
        PTensor w = inp[0];
        PTensor x = inp[1];

        return mult(w, x);
    }
};

class SigmoidNode: public OpNode
{
private:
    PTensor compute(vector<PTensor> inp)
    {
        PTensor x = inp[0];

        return 1 / (1 + pint::exp(-x));
    }
};

void printPTensor(PTensor t);

}

#endif
