#include <string>
#include <map>
#include "opnode.h"

using namespace std;

namespace pint
{

class OpGraph
{
private:
  map<string, OpNode *> nodes;

public:
  OpGraph* addNode(string node_id, string left_parent_id = "", string right_parent_id = "", double (*func)(double, double) = NULL);
  // TODO: is it possible to make the function pointer more generic, i.e. for int* instead of double*
  OpGraph* setNode(string node_id, PTensor value);
  PTensor evalNode(string node_id);

};

}
