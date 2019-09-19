#include <string>
using namespace std;

class Node
{
public:
  unsigned int node_id;
  string node_name;
  unsigned int left_parent;
  unsigned int right_parent;
  void *operation;

};
