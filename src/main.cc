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

    printf("INPUT:\n");
    //printPTensorData(*input);
    //printf("\n");
    //printPTensor(*input);

    printf("MAKING SNN\n");
    SequentialNet *net = new SequentialNet();

    printf("AdDDING LAYERS\n");

    net->addLayer(2,3);
    net->addLayer(3,1);

    printf("INITIAL WEIGHTS:\n");
    printWeights(net->weights);

    printf("\nRUNNING SNN\n");
    PTensor output = net->run(input);

    printf("\nOUTPUT:\n");
    printPTensor(output);

    PTensor *expected = new PTensor();
    expected->at(0) = 1;

    printf("\nDOING BACKPROP\n");
    net->backwardProp(expected);
    
    printf("\nNEW WEIGHTS:\n");
    printWeights(net->weights); 

    return 0;
}
