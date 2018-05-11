/**
*	@file : Node.cpp
*	@author :  Richard Aviles
*	@date : 2018.02.13
*	Purpose: Creates the Node and its methods.
*/

using namespace std;

#include "Node.h"

Node::Node(string d)
{
  m_next = nullptr;
  data = d;
}

Node::~Node()
{

}

void Node::setNext(Node* n)
{
  m_next = n;
}

Node* Node::getNext()
{
  return m_next;
}
