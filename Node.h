#include <string>
using namespace std;

class Node
{
public:
  Node* left_parent;
  Node* right_parent;
  void *operation;
  void *derivate;
  double result;

  Node(Node* left, Node* right, void *func)
  {
    this->left_parent = left;
    this->right_parent = right;
    this->operation = func;
  }
};
