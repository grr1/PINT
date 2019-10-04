//TODO: make virtual and do away with function.h
//TODO: make PTensor wrapper for 2D/3Darray or tensor allocation, use xtensor if needed

#include <string>

using namespace std;

namespace pint
{

class OpNode
{
private:
  string node_id;
  OpNode* left_parent;
  OpNode* right_parent;
  double (*operation)(double, double);
  void *derivate;
  double result;
  bool pin;

  double compute();

public:
  OpNode(string, OpNode*, OpNode*, double (*func)(double, double));
  void setPin(bool);
  bool getPin();
  void setResult(double);
  double getResult();

};

}
