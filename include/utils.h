#ifndef UTILS_H
#define UTILS_H

#include "pint.h"

namespace pint
{

int init();

class PlusNode: public OpNode
{
private:
    PTensor compute(PTensor left, PTensor right)
    {
        return left + right;
    } 
};

class MultNode: public OpNode
{
private:
    PTensor compute(PTensor left, PTensor right)
    {
        return left * right;
    } 
};

class ReflexvityNode: public OpNode
{
    private:
        PTensor* tensor;

    public:
        PTensor* setTensor(PTensor* inputTensor)
        {
            this->tensor = inputTensor;
        }
        PTensor* compute()
        {
            return this->tensor;
        }
}

class DotProductNode: public OpNode
{
    public:
        PTensor* compute(PTensor *left, PTensor* right)
        {
            return left.dotProduct(right);
        }
}

class ActivationNode: public OpNode
{

}

void printPTensor(PTensor t);

}

#endif
