#include "pint.h"
#include <iostream>

using namespace pint;

<<<<<<< HEAD
void sequentialNetworkExample()
=======
int test243()
>>>>>>> 6c708ac48e72c3bb7076d24015cc0d806a4ab957
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
<<<<<<< HEAD

    printf("MAKING NN\n");
=======
    printPTensor(*expected2);

    printf("MAKING SNN\n");
>>>>>>> 6c708ac48e72c3bb7076d24015cc0d806a4ab957
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

    vector<PTensor*> inputs;
    inputs.push_back(input);
    inputs.push_back(input2);
    vector<PTensor*> expectedOuts;
    expectedOuts.push_back(expected);
    expectedOuts.push_back(expected2);

    printf("\nREADY TO TRAIN\n");

    getchar();

<<<<<<< HEAD
    for (int i = 0; i < 5000; i++)
    {
        printf("\nITERATION %d\n", i);
=======
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
}

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
>>>>>>> 6c708ac48e72c3bb7076d24015cc0d806a4ab957

    printf("INITIAL WEIGHTS:\n");
    printWeights(net->weights);

    printf("\nNO ITER\n");

    printf("\nRUNNING SNN\n");
    PTensor output = net->run(input);

<<<<<<< HEAD
        printf("\nDOING BACKPROP\n");
        net->backwardProp(expected);

        printf("\nNEW WEIGHTS:\n");
        printWeights(net->weights);

        //getchar();
    }
=======
    printf("\nFIRST OUTPUT:\n");
    printPTensor(*(net->layerOuts[0]->_result));
    printPTensor(output);

    printf("\nFIRST BACKPROP\n");
    net->backwardProp(expected);
    
    printf("\nFIRST NEW WEIGHTS:\n");
    printWeights(net->weights);

    vector<PTensor*> inputs;
    inputs.push_back(input);
    vector<PTensor*> expectedOuts;
    expectedOuts.push_back(expected);

    printf("\nREADY TO TRAIN\n");

    getchar();

    printf("\nTRAINING...\n");

    net->basicTrain(inputs, expectedOuts, 2000000, 0.02);

    printf("\nFINAL WEIGHTS\n");
    printWeights(net->weights);
>>>>>>> 6c708ac48e72c3bb7076d24015cc0d806a4ab957

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

int main(int argc, char** argv)
{
    
    if (pint::init()) { exit(1); }
    
    printf("\nTEST 243\n");
    test243();

    getchar();

    printf("\nXOR TEST\n");
    xorTest();

    return 0;
}
