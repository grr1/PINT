#include <string>
using namespace std;

class Node
{
public:
  string node_id;
  Node* left_parent;
  Node* right_parent;
  double (*operation)(double, double);
  void *derivate;
  double result;

  Node(string node_id, Node* left, Node* right, double (*func)(double, double))
  {
    this->node_id = node_id;
    this->left_parent = left;
    this->right_parent = right;
    this->operation = func;
  }
};
