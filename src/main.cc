#include "pint.h"
#include <iostream>

using namespace pint;

void sequentialNetworkExample()
{
    if (pint::init()) { exit(1); }

    int shape[3];
    shape[0] = 2;
    shape[1] = 1;
    shape[2] = 1;
    PTensor *input = new PTensor(3, shape);
    input->at(0) = 5; // x
    input->at(1) = 4; // y

    shape[0] = 3;
    shape[1] = 1;
    shape[2] = 1;
    PTensor *expected = new PTensor(3, shape);
    expected->at(0) = 0.1; // a
    expected->at(1) = 0.4; // b
    expected->at(2) = 0.8; // c

    printf("INPUT:\n");
    printPTensor(*input);

    printf("\nEXPECTED OUTPUT:\n");
    printPTensor(*expected);

    printf("MAKING NN\n");
    SequentialNet *net = new SequentialNet();

    printf("ADDING LAYERS\n");
    net->addLayer(2, 4);
    net->addLayer(4, 3);

    printf("INITIAL WEIGHTS:\n");
    printWeights(net->weights);

    printf("\nNO ITER\n");

    printf("\nRUNNING NN\n");
    PTensor output = net->run(input);

    printf("\nFIRST OUTPUT:\n");
    printPTensor(output);

    printf("\nFIRST BACKPROP\n");
    net->backwardProp(expected);

    printf("\nFIRST NEW WEIGHTS:\n");
    printWeights(net->weights);

    getchar();

    for (int i = 0; i < 5000; i++)
    {
        printf("\nITERATION %d\n", i);

        printf("\nRUNNING SNN\n");
        output = net->run(input);

        printf("\nOUTPUT:\n");
        printPTensor(output);

        printf("\nDOING BACKPROP\n");
        net->backwardProp(expected);

        printf("\nNEW WEIGHTS:\n");
        printWeights(net->weights);

        //getchar();
    }

    printf("\nFINAL RESULT:\n");
    output = net->run(input);
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

void sequentialSaveLoadExample() {
    // building from scratch
    SequentialNet* net = new SequentialNet();
    net->addLayer(2, 3);
    net->AddLayer(3, 3);
    net->AddLayer(3, 5);

    // saving
    
}

int main()
{
    if (pint::init()) { exit(1); }

    //sequentialNetworkExample();
    xorExample();
    sequentialSaveLoadExample();

    return 0;
}
