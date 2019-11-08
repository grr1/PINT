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

void printPTensor(PTensor t);

}

#endif
