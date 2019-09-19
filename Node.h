#include <string>
using namespace std;

class Node
{
public:
  Node* left_parent;
  Node* right_parent;
  double (*operation)(double, double);
  void *derivate;
  double result;

  Node(Node* left, Node* right, double (*func)(double, double))
  {
    this->left_parent = left;
    this->right_parent = right;
    this->operation = func;
  }
};
