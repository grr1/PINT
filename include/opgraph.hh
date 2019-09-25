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
  OpGraph* addNode(string node_id, string left_parent_id = "", string right_parent_id = "", double (*func)(double, double) = NULL);
  OpGraph* setNode(string node_id, double value);
  double   evalNode(string node_id);
};
