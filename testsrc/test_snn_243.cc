#include "pint.h"

using namespace pint;

int main()
{
    if (pint::init()) { exit(1); }

    cout << "INPUT:" << endl;
    int shape[3];
    shape[0] = 2;
    shape[1] = 2;
    shape[2] = 1;
    PTensor *input = new PTensor(3, shape);
    /*
        5 1
        4 3
    */
    input->at(0,0) = 5; // 1x
    input->at(1,0) = 4; // 1y
    input->at(0,1) = 1; // 2x
    input->at(1,1) = 3; // 2y
    cout << *input << endl;


    cout << "EXPECTED OUTPUT:" << endl;
    shape[0] = 3;
    shape[1] = 2;
    shape[2] = 1;
    PTensor *expected = new PTensor(3, shape);
    /*
        0.1   0.6
        0.4   0.2
        0.7   0.9
    */
    expected->at(0,0) = 0.1; // 1a
    expected->at(1,0) = 0.4; // 1b
    expected->at(2,0) = 0.7; // 1c
    expected->at(0,0) = 0.6; // 2a
    expected->at(1,0) = 0.2; // 2b
    expected->at(2,0) = 0.9; // 2c
    cout << *expected << endl;

    cout << endl;

    cout << "INITIALIZING NET . . ." << endl;
    SequentialNet *net = new SequentialNet();

    cout << "ADDING LAYERS . . ." << endl;
    net->addLayer(2, 4);
    net->addLayer(4, 3);

    cout << endl;

    cout << "INITIAL WEIGHTS:" << endl;
    cout << net->weights << endl;

    cout << "INITIAL OUTPUT:" << endl;
    PTensor output = net->run(input);
    cout << output << endl;

    cout << endl;

    cout << "TRAINING . . ." << endl;
    net->train(input, expected, 50000, 1, 0.04);

    cout << endl;

    cout << "FINAL WEIGHTS:" << endl;
    cout << net->weights << endl;

    cout << "FINAL OUTPUT:" << endl;
    output = net->run(input);
    cout << output << endl;

    return 0;
}
