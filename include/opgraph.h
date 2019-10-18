#ifndef OPGRAPH_H
#define OPGRAPH_H

#include "pint.h"

#include <string>
#include <map>

using namespace std;

namespace pint
{

class OpGraph
{
private:
  map<string, OpNode *> nodes;

public:
  OpGraph* addNode(string node_id, OpNode * node, string left_parent_id = "", string right_parent_id = "");
  OpGraph* setNode(string node_id, PTensor value);
  PTensor evalNode(string node_id);

};

}

#endif
