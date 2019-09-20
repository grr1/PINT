#include <pint.h>

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Graph
{
private:
  map<string, Node *> nodes;

public:
  Graph* addNode(string node_id, string left_parent_id = "", string right_parent_id = "", double (*func)(double, double) = NULL) // TODO is it possible to make the function pointer more generic, i.e. for int* instead of double*
  {
    Node *left_parent  = nodes.count(left_parent_id)>0 ? nodes[left_parent_id]: NULL;
    Node *right_parent = nodes.count(right_parent_id)>0 ? nodes[right_parent_id]: NULL;
    Node *node = new Node(node_id,left_parent, right_parent, func);
    this->nodes.insert(pair<string, Node *>(node_id, node));
    return this;
  }

  Graph* setNode(string node_id, double value)
  {
    this->nodes[node_id]->setResult(value);
    return this;
  }

  double evalNode(string node_id)
  {
    return this->nodes[node_id]->getResult();
  }

};

int main() // TODO: move this to its respective main.cc file eventually for future testing, update Makefile
{
  Graph g;
  //Add two nodes
  g.addNode("a")->addNode("b")->addNode("+","a","b",dAdd)->setNode("a",3)->setNode("b",4);

  //Multiply result of node with constant
  g.addNode("c")->addNode("*","+","c",dMult)->setNode("c",5)->setNode("+",2);

  //Evaluate it
  cout << g.evalNode("*") <<endl;
  return 0;
}
