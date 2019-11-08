#include "pint.h"

using namespace pint;

OpNode::OpNode()
{
}

OpNode::OpNode(vector<OpNode *> parents)
{
    _parents = parents;
}

OpNode::~OpNode()
{
}

PTensor OpNode::eval()
{
    //if (_set) { return _result; }

    vector<PTensor> inp;

    for (uint i = 0; i < _parents.size(); i++) { inp.push_back(_parents[i]->eval()); } 

    return _result = compute(inp);
}

/*void OpNode::setResult(PTensor result)
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
}*/
