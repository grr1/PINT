#include "pint.h"
#include <iostream>

using namespace pint;

int main()
{
    if (pint::init()) { exit(1); }
    const int input[] = {3,5};
    PTensor *input = new PTensor(2, input);
    NeuralNetwork *net = new NeuralNetwork();
    net->addLayer(2,3);
    net->addLayer(3,1);
    PTensor *output = net.run(input);
    return 0;
}
