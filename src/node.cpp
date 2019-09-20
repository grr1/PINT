#include "pint.hh"

Node::Node(string node_id, Node* left, Node* right, double (*func)(double, double))
{
  this->node_id = node_id;
  this->left_parent = left;
  this->right_parent = right;
  this->operation = func;
  this->pin = false;
}

double Node::compute()
{
  return (this->operation)(this->left_parent->getResult(), this->right_parent->getResult());
}

double Node::getResult()
{
  if(this->getPin())
  {
    return this->result;
  }
  else
  {
    return this->compute();
  }
}

void Node::setResult(double value)
{
  this->result = value;
  this->setPin(true);
}

bool Node::getPin()
{
  return this->pin;
}

void Node::setPin(bool val)
{
  this->pin = true;
}
