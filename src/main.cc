#include "pint.h"
#include <iostream>

using namespace pint;

int main()
{
    if (pint::init()) { exit(1); }

    const int inp_shape[] = {2,1};
    PTensor *input = new PTensor(2, inp_shape);

    input->at(0) = 5; // x
    input->at(1) = 4; // y

    printf("input:\n");
    printPTensorData(*input);
    printf("\n");
    printPTensor(*input);

    printf("Making net\n");

    SequentialNet *net = new SequentialNet();

    printf("Adding layers\n");

    net->addLayer(2,3);
    net->addLayer(3,1);

    printf("Weights:\n");
    printWeights(net->weights);

    printf("\nRunning net\n");

    PTensor output = net->run(input);

    printf("\n\noutput:\n");
    printPTensorData(output);
    printf("\n");
    printPTensor(output);

    return 0;
}
