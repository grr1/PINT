#include "pint.h"
#include <iostream>

using namespace pint;

void sequentialNetworkExample() {
    const int inp_shape[] = {2,1};
    PTensor *input = new PTensor(2, inp_shape);

    input->at(0) = 5; // x
    input->at(1) = 4; // y

    printf("input:\n");
    //printPTensorData(*input);
    //printf("\n");
    printPTensor(*input);

    printf("Making net\n");

    NonSequentialNet *net = new NonSequentialNet();

    printf("Adding layers\n");

    net->addLayer(2, 3, "L1", "");
    net->addLayer(3, 1, "L2", "L1");

    printf("Weights:\n");
    printWeights(net->weights);

    printf("\nRunning net\n");

    PTensor output = net->run(input, "L2");

    printf("\n\noutput:\n");
    //printPTensorData(output);
    //printf("\n");
    printPTensor(output);
}

void xorExample() {
    // TODO configure real inputs here
    const int inp_shape[] = {2, 1};
    PTensor* input = new PTensor(2, inp_shape);

    input->at(0) = 5;
    input->at(1) = 4;

    printf("Input:\n");
    printPTensor(*input);

    printf("Making the network...\n");
    NonSequentialNet* net = new NonSequentialNet();

    printf("Adding layers...\n");
    net->addLayer(2, 2, "L1", "");
    net->addLayer(2, 1, "L2", "L1");

    printf("Initial weights:\n");
    printWeights(net->weights);

    printf("Running net...\n");
    PTensor output = net->run(input, "L2");

    printf("End weights:\n");
    printWeights(net->weights);

    printf("Output:\n");
    printPTensor(output);
}

int main()
{
    if (pint::init()) { exit(1); }

    //sequentialNetworkExample();
    xorExample();

    return 0;
}
