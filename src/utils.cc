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

void pint::printPTensorData(const PTensor &t)
{
    for (int i = 0; i < t._size; i++)
    {
        printf("%d:\t%f\n", i, t._data[i]);
    }
}

void pint::printPTensor(const PTensor &t)
{
    printf("[%d,%d,%d]\n\n", t._shape[0], t._shape[1], t._shape[2]);
    for (int k = 0; k < t._shape[2]; k++)
    {
        printf("k=%d\n", k);
        for (int i = 0; i < t._shape[0]; i++)
        {
            printf("\t%f", t.at(i, 0, k));
            for (int j = 1; j < t._shape[1]; j++)
            {
                printf("\t%f", t.at(i,j,k));
            }
            printf("\n");
        }
        printf("\n");
    }
}

void pint::printWeights(const vector<PTensor*> &weights)
{
    for (int i = 0; i < weights.size(); i++)
    {
        printf("weight %d:\n", i);
        printPTensor(*(weights[i]));
    }
}
