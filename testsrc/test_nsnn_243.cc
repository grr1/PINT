#include "pint.h"

using namespace pint;

int main() {
    if (pint::init()) { exit(1); }

    cout << "INPUT:" << endl;
    int shape[3] = {2,2,1};
    PTensor* input = new PTensor(3, shape);
    /*
        5 1
        4 3
    */
    input->at(0,0) = 5; // 1x
    input->at(1,0) = 4; // 1y
    input->at(0,1) = 1; // 2x
    input->at(1,1) = 3; // 2y
    cout << *input << endl;

    cout << endl;

    cout << "INITIALIZING NET . . ." << endl;
    NonSequentialNet* net = new NonSequentialNet();

    cout << "ADDING LAYERS . . ." << endl;
    net->addLayer(2, 4, "L1");
    net->addLayer(4, 3, "L2", "L1");

    cout << endl;

    cout << "WEIGHTS:" << endl;
    cout << net->weights << endl; 

    cout << "OUTPUT:" << endl;
    PTensor output = net->run(input, "L2");
    cout << output << endl;

    return 0;
}
