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

    public:
        void setTensor(PTensor* inputTensor)
        {
            this->tensor = inputTensor;
        }
        PTensor compute()
        {
            return *(this->tensor);
        }
};

class DotProductNode: public OpNode
{
    private:
        PTensor compute(PTensor *left, PTensor* right)
        {
            return dot(*left, *right);
        }
};

class ActivationNode: public OpNode
{
public:
    PTensor compute(PTensor x)
    {
       return 1 / (1 + ptexp(-x));
    }
};

void printPTensor(PTensor t);

}

#endif
