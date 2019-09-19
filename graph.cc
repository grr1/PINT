#include <string>
#include <map>
#include "Node.h"
#include "Functions.h"
using namespace std;

class Graph
{
private:
  map<string, Node *> nodes;

public:
  Graph addNode(string node_id, string left_parent_id = "", string right_parent_id = "", void *func = NULL)
  {
    Node *left_parent  = nodes[left_parent_id];
    Node *right_parent = nodes[right_parent_id];
    Node node(left_parent, right_parent, func);
    nodes.insert(pair<string, Node *>(node_id, &node));
    return *this;
  }

  Graph setNode(string node_id, double value)
  {
    nodes[node_id]->result = value;
    return *this;
  }

  Graph evalNode(string node_id)
  {
    Node *node = nodes[node_id];
   // Find a way to invoke function
   //(node->operation)(node->left_parent->result, node->right_parent->result);
   return *this;
  }

};

int main()
{
  Graph g;
  g.addNode("a").addNode("b");
  g.addNode("+","a","b", (void *)add);
  g.setNode("a",3).setNode("b",3);
  g.evalNode("+");
  return 0;
}
