#include "opnode.h"

using namespace pint;

OpNode::OpNode(OpNode* left, OpNode* right)
{
  left_parent = left;
  right_parent = right;
}

OpNode::~OpNode()
{
}

PTensor OpNode::eval()
{
    if (_set) { return _result; }

    return _result = compute(left_parent->eval(), right_parent->eval());
}

void OpNode::setResult(PTensor result)
{
    _set = true;
    _result = result;
}

PTensor OpNode::getResult()
{
    return _result;
}

PTensor OpNode::unsetResult()
{
    _set = false;
    return _result;
}
