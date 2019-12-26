#include "pint.h"

using namespace pint;

int main()
{
    if (pint::init()) { exit(1); }

    cout << "INPUT:" << endl;
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
    cout << *input << endl;

    cout << "EXPECTED OUTPUT:" << endl;
    shape[0] = 1;
    shape[1] = 4;
    shape[2] = 1;
    PTensor *expected = new PTensor(3, shape);
    /*
        0 1 1 0
    */
    expected->at(0) = expected->at(3) = 0;
    expected->at(1) = expected->at(2) = 1;
    cout << *expected << endl;

    cout << "INITIALIZING NET . . ." << endl;
    SequentialNet *net = new SequentialNet();

    cout << "ADDING LAYERS . . ." << endl;
    net->addLayer(2,2);
    net->addLayer(2,1);

    cout << endl;

    cout << "INITIAL WEIGHTS:" << endl;
    cout << net->weights << endl;

    cout << "INITIAL OUTPUT:" << endl;
    PTensor output = net->run(input);
    cout << output << endl;

    cout << endl;

    cout << "TRAINING . . ." << endl;
    net->train(input, expected, 2000000, 2, 0.02);

    cout << endl;

    cout << "FINAL WEIGHTS:" << endl;
    cout << net->weights << endl;

    cout << "FINAL OUTPUT:" << endl;
    output = net->run(input);
    cout << output << endl;

    return 0;
}
