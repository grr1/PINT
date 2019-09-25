#include "pint.hh"
#include <iostream>

int main()
{
  printf("Hello, world!\n");

  OpGraph g;
  //Add two nodes
  g.addNode("a")->addNode("b")->addNode("+","a","b",dAdd)->setNode("a",3)->setNode("b",4);

  //Multiply result of node with constant
  g.addNode("c")->addNode("*","+","c",dMult)->setNode("c",5)->setNode("+",2);

  //Evaluate it
  cout << g.evalNode("*") <<endl;
  return 0;
}
