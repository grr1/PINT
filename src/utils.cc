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
    printf("[\n");
    for (int k = 0; k < t._shape[2]; k++)
    {
        printf("[");
        for (int j = 0; j < t._shape[1]; j++)
        {
            printf("\t[%f", t.getElement(0, j, k));
            for (int i = 1; i < t._shape[0]; i++)
            {
                printf(", %f", t.getElement(i, j, k));
            }
            printf("]\n");
        }
        printf("\t]\n");
    }
    printf("]\n");
}
