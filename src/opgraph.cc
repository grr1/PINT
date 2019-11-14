// TODO: get opgraph up to speed once we start working on node ids

#include "pint.h"

#include <string>
#include <map>

using namespace pint;
/*
OpGraph* OpGraph::addNode(string node_id, OpNode * node, string left_parent_id, string right_parent_id)
{
    OpNode *left  = nodes.count(left_parent_id)>0 ? nodes[left_parent_id]: NULL;
    OpNode *right = nodes.count(right_parent_id)>0 ? nodes[right_parent_id]: NULL;
    node->left_parent = left;
    node->right_parent = right;
    this->nodes.insert(pair<string, OpNode *>(node_id, node));
    return this;
}

OpGraph* OpGraph::setNode(string node_id, PTensor value)
{
    this->nodes[node_id]->setResult(value);
    return this;
}

PTensor OpGraph::evalNode(string node_id)
{
    return this->nodes[node_id]->eval();
}
*/
