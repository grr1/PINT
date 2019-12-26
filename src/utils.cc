// TODO: replace printfs with error util
// TODO: replace printfs with debug util

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

ostream & pint::operator<<(ostream &os, const PTensor &t)
{
    os << "[" << endl;
    for (int k = 0; k < t._shape[2]; k++)
    {
        os << "\t[";
        for (int i = 0; i < t._shape[0]; i++)
        {
            os << "\t";
            for (int j = 0; j < t._shape[1]; j++)
            {
// TODO: fix precision printing on cout for doubles
                os << setw(8) << setfill('0') << t.at(i,j,k) << "\t";
            }
            if (i != t._shape[0]-1)
            {
                os << endl << "\t";
            }
        }
        os << "]" << endl;
    }
    os << "]";

    return os;
}

ostream & pint::operator<<(ostream &os, const vector<PTensor*> &w)
{
    os << "{" << endl;

    for (int i = 0; i < w.size(); i++)
    {
        os << *w[i] << endl;
    }

    os << "}";

    return os;
}
