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
  void addNode(string node_id, string left_parent_id = "", string right_parent_id = "", double (*func)(double, double) = NULL)
  {
    Node *left_parent  = nodes.count(left_parent_id)>0 ? nodes[left_parent_id]: NULL;
    Node *right_parent = nodes.count(right_parent_id)>0 ? nodes[right_parent_id]: NULL;
    Node *node = new Node(node_id,left_parent, right_parent, func);
    this->nodes.insert(pair<string, Node *>(node_id, node));
  }

  void setNode(string node_id, double value)
  {
    cout<<this->nodes.count(node_id)<<endl;
    cout<<this->nodes[node_id]->node_id;
    this->nodes[node_id]->result = value;
  }

  double evalNode(string node_id)
  {
    Node *node = this->nodes[node_id];
    cout << node->node_id;
   return 0;// (node->operation)(node->left_parent->result, node->right_parent->result);
  }

};

int main()
{
  Graph g;
  g.addNode("a");
  //g.addNode("b");
  //g.addNode("+","a","b",add);
  g.setNode("a",3);
  //g.setNode("b",3);
  //cout << g.evalNode("+");
  return 0;
}
