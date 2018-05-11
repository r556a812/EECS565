/**
*	@file : Node.h
*	@author : Richard Aviles
*	@date : 2018.02.13
	Purpose: The header file for Node.
*/

#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
    public:
      Node(std::string d);
      ~Node();
      void setNext(Node* n);
      Node* getNext();
      Node* m_next;
      std::string data;
};

#endif
