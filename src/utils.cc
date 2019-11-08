#include "pint.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace pint;

int pint::init()
{
    srand(time(NULL));
    return 0;
}

void pint::printPTensor(PTensor t)
{
    for (int k = 0; k < t._shape[2]; k++)
    {
        for (int i = 0; i < t._shape[0]; i++)
        {
            printf("%f", t.getElement(i, 0, k));
            for (int j = 1; j < t._shape[t]; j++)
            {
                printf("\t%f", t.getElement(i, j, k));
            }
            printf("\n");
        }
        printf("\n");
    }
}
