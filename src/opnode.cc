#include "pint.h"

using namespace pint;

OpNode::OpNode()
{
    _result = new PTensor();
}

OpNode::OpNode(vector<OpNode *> parents)
{
    _result = new PTensor();
    _parents = parents;
}

OpNode::~OpNode()
{
}

PTensor OpNode::eval()
{
    //if (_set) { return _result; }

    vector<PTensor*> inp;

    for (uint i = 0; i < _parents.size(); i++)
    {
        _parents[i]->eval();
        inp.push_back(_parents[i]->_result);
    }

    return *_result = compute(inp);
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
