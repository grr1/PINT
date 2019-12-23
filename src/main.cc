// TODO: replace printfs with error util
// TODO: replace printfs with debug util
// TODO: cout instead of printf

#include "pint.h"
#include <iostream>

using namespace pint;

// TODO: resetup test243 for batching instead of vector<PTensor>
/*int test243()
{

    int shape[3];
    shape[0] = 2;
    shape[1] = 1;
    shape[2] = 1;
    PTensor *input = new PTensor(3, shape);
    input->at(0) = 5; // x
    input->at(1) = 4; // y

    PTensor *input2 = new PTensor(3, shape);
    input2->at(0) = 1; // x
    input2->at(1) = 3; // y


    shape[0] = 3;
    shape[1] = 1;
    shape[2] = 1;
    PTensor *expected = new PTensor(3, shape);
    expected->at(0) = 0.1; // a
    expected->at(1) = 0.4; // b
    expected->at(2) = 0.7; // c

    PTensor *expected2 = new PTensor(3, shape);
    expected2->at(0) = 0.6; // a
    expected2->at(1) = 0.2; // b
    expected2->at(2) = 0.9; // c


    printf("INPUT:\n");
    printPTensor(*input);
    printPTensor(*input2);

    printf("\nEXPECTED OUTPUT:\n");
    printPTensor(*expected);
    printPTensor(*expected2);

    printf("MAKING SNN\n");
    SequentialNet *net = new SequentialNet();

    printf("ADDING LAYERS\n");
    net->addLayer(2,4);
    net->addLayer(4,3);

    printf("INITIAL WEIGHTS:\n");
    printWeights(net->weights);

    printf("\nNO ITER\n");

    printf("\nRUNNING SNN\n");
    PTensor output = net->run(input);

    printf("\nFIRST OUTPUT:\n");
    printPTensor(output);

    printf("\nFIRST BACKPROP\n");
    net->backwardProp(expected);
    
    printf("\nFIRST NEW WEIGHTS:\n");
    printWeights(net->weights);

    vector<PTensor*> inputs;
    inputs.push_back(input);
    inputs.push_back(input2);
    vector<PTensor*> expectedOuts;
    expectedOuts.push_back(expected);
    expectedOuts.push_back(expected2);

    printf("\nREADY TO TRAIN\n");

    getchar();

    printf("\nTRAINING...\n");

    net->basicTrain(inputs, expectedOuts, 50000);

    printf("\nFINAL WEIGHTS\n");
    printWeights(net->weights);

    printf("\nFINAL RESULT:\n");
    output = net->run(input);
    printPTensor(output);
    output = net->run(input2);
    printPTensor(output);

    return 0;
}*/

int xorTest()
{
   int shape[3];
    shape[0] = 2;
    shape[1] = 4;
    shape[2] = 1;
    PTensor *input = new PTensor(3, shape);
    /*
        0 1 0 1
        0 0 1 1
    */
    input->at(0,0) = input->at(1,0) = input->at(1,1) = input->at(0,2) = 0;
    input->at(0,1) = input->at(1,2) = input->at(0,3) = input->at(1,3) = 1;

    shape[0] = 1;
    shape[1] = 4;
    shape[2] = 1;
    PTensor *expected = new PTensor(3, shape);
    /*
        0 1 1 0
    */
    expected->at(0) = expected->at(3) = 0;
    expected->at(1) = expected->at(2) = 1;

    printf("INPUT:\n");
    printPTensor(*input);

    printf("\nEXPECTED OUTPUT:\n");
    printPTensor(*expected);


    printf("MAKING SNN\n");
    SequentialNet *net = new SequentialNet();

    printf("ADDING LAYERS\n");
    net->addLayer(2,2);
    net->addLayer(2,1);

    printf("INITIAL WEIGHTS:\n");
    printWeights(net->weights);

    printf("\nNO ITER\n");

    printf("\nRUNNING SNN\n");
    PTensor output = net->run(input);

    printf("\nFIRST OUTPUT:\n");
    printPTensor(*(net->layerOuts[0]->_result));
    printPTensor(output);

    printf("\nFIRST BACKPROP\n");
    net->backwardProp(expected);
    
    printf("\nFIRST NEW WEIGHTS:\n");
    printWeights(net->weights);

    printf("\nREADY TO TRAIN\n");

//    getchar();

    printf("\nTRAINING...\n");

    net->train(input, expected, 2000000, 2, 0.02);

    printf("\nFINAL WEIGHTS\n");
    printWeights(net->weights);

    printf("\nFINAL RESULT:\n");
    output = net->run(input);
    printPTensor(output);

    return 0;
}

int main(int argc, char** argv)
{
    
    if (pint::init()) { exit(1); }
    
//    printf("\nTEST 243\n");
//    test243();

//    getchar();

    printf("\nXOR TEST\n");
    xorTest();

    return 0;
}
