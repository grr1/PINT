//TODO: change nomenclature

#include <string>
#include <map>
#include "opgraph.h"

using namespace pint;

OpGraph* OpGraph::addNode(string node_id, string left_parent_id, string right_parent_id, double (*func)(double, double))
{
    OpNode *left_parent  = nodes.count(left_parent_id)>0 ? nodes[left_parent_id]: NULL;
    OpNode *right_parent = nodes.count(right_parent_id)>0 ? nodes[right_parent_id]: NULL;
    OpNode *node = new OpNode(node_id,left_parent, right_parent, func);
    this->nodes.insert(pair<string, OpNode *>(node_id, node));
    return this;
}

OpGraph* OpGraph::setNode(string node_id, double value)
{
    this->nodes[node_id]->setResult(value);
    return this;
}

double OpGraph::evalNode(string node_id)
{
    return this->nodes[node_id]->getResult();
}
