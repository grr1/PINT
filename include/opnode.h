//TODO: make virtual and do away with function.h

#include <string>
#include "ptensor.h"

using namespace std;

namespace pint
{

class OpNode
{
private:
  OpNode* left_parent;
  OpNode* right_parent;
  PTensor * result; // TODO: store as pointer for easier passing?
  bool set;

  virtual PTensor compute() {};
  virtual PTensor derivative() {};

public:
  OpNode(OpNode*, OpNode*);
  ~OpNode();

  PTensor eval();

  void setResult(PTensor);
  PTensor unsetResult();

};

}
