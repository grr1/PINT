//TODO: make abstract and merge with function pseudo-class

#include <string>

using namespace std;

class OpNode
{
private:
  OpNode* left_parent;
  OpNode* right_parent;
  //vector<OpNode*> parents;
  double (*operation)(double, double);
  void *derivate;
  double result;
  bool pin;

  double compute();

public:
  OpNode(OpNode*, OpNode*, double (*func)(double, double));
  void setPin(bool);
  bool getPin();
  void setResult(double);
  double getResult();
};
