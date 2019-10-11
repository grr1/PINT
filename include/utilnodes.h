#include "opnode.h"

namespace pint
{

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

}
