#include <iostream>
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
  Graph addNode(string node_id, string left_parent_id = "", string right_parent_id = "", double (*func)(double, double) = NULL)
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

  double evalNode(string node_id)
  {
    Node *node = nodes[node_id];
   // Find a way to invoke function
   return (node->operation)(node->left_parent->result, node->right_parent->result);
  }

};

int main()
{
  Graph g;
  g.addNode("a").addNode("b");
  g.addNode("+","a","b",add);
  g.setNode("a",3).setNode("b",4);
  cout << g.evalNode("+");
  return 0;
}
