#include "opnode.hh"
OpNode::OpNode(OpNode* left, OpNode* right, double (*func)(double, double))
{
  this->left_parent = left;
  this->right_parent = right;
  this->operation = func;
  this->pin = false;
}

double OpNode::compute()
{
  return (this->operation)(this->left_parent->getResult(), this->right_parent->getResult());
}

/*
void OpNode::addParent(string parent_node_id)
{
  this->parents.push_back(this->nodes[]);
}*/

double OpNode::getResult()
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

void OpNode::setResult(double value)
{
  this->result = value;
  this->setPin(true);
}

bool OpNode::getPin()
{
  return this->pin;
}

void OpNode::setPin(bool val)
{
  this->pin = true;
}
