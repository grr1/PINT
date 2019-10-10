#include "opnode.h"

using namespace pint;

OpNode::OpNode(OpNode* left, OpNode* right)
{
  this->left_parent = left;
  this->right_parent = right;
  this->result = NULL;
}

PTensor OpNode::eval()
{
    return *result;
}
