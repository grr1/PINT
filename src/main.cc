#include "pint.h"
#include <iostream>

using namespace pint;

int main()
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


    printf("MAKING SNN\n");
    SequentialNet *net = new SequentialNet();

    printf("ADDING LAYERS\n");
    net->addLayer(2,4);
    net->addLayer(4,3);

    printf("INITIAL WEIGHTS:\n");
    printWeights(net->weights);

    for (int i = 0; i < 2000; i++)
    {
        printf("\nITERATION %d\n", i);

        printf("\nRUNNING SNN\n");
        PTensor output = net->run(input);

        printf("\nOUTPUT:\n");
        printPTensor(output);

        printf("\nDOING BACKPROP\n");
        net->backwardProp(expected);
    
        printf("\nNEW WEIGHTS:\n");
        printWeights(net->weights);

        //getchar(); 
    }

    printf("\nFINAL RESULT:\n");
    PTensor output = net->run(input);
    printPTensor(output);

    return 0;
}
