//TODO: make virtual and do away with function.h

#include "ptensor.h"

using namespace std;

namespace pint
{

class OpNode
{
private:
  OpNode* left_parent;
  OpNode* right_parent;
  PTensor _result; // TODO: store as pointer for easier passing?
  bool _set = false;

  virtual PTensor compute(PTensor, PTensor) {};
  virtual PTensor derivative() {};

public:
  OpNode(OpNode*, OpNode*);
  ~OpNode();

  PTensor eval();

  void setResult(PTensor);
  PTensor getResult();
  PTensor unsetResult();

};

}
