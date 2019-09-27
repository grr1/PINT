//TODO: change nomenclature

#include <string>
#include <map>
#include "opnode.hh"

using namespace std;

class OpGraph
{
private:
  map<string, OpNode *> nodes;

public:
  OpGraph* addNode(string node_id, string left_parent_id = "", string right_parent_id = "", double (*func)(double, double) = NULL) // TODO is it possible to make the function pointer more generic, i.e. for int* instead of double*
  {
    OpNode *left_parent  = nodes.count(left_parent_id)>0 ? nodes[left_parent_id]: NULL;
    OpNode *right_parent = nodes.count(right_parent_id)>0 ? nodes[right_parent_id]: NULL;
    OpNode *node = new OpNode(node_id,left_parent, right_parent, func);
    this->nodes.insert(pair<string, OpNode *>(node_id, node));
    return this;
  }

  OpGraph* setNode(string node_id, double value)
  {
    this->nodes[node_id]->setResult(value);
    return this;
  }

  double evalNode(string node_id)
  {
    return this->nodes[node_id]->getResult();
  }

};
