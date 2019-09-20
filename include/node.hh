#include <string>

using namespace std;

class Node
{
private:
  string node_id;
  Node* left_parent;
  Node* right_parent;
  double (*operation)(double, double);
  void *derivate;
  double result;
  bool pin;

  double compute();

public:
  Node(string, Node*, Node*, double (*func)(double, double));
  void setPin(bool);
  bool getPin();
  void setResult(double);
  double getResult();

};
