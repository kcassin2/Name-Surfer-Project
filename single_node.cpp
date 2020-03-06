#include "single_node.h"
#ifndef NODE_CPP
#define NODE_CPP
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <ios>
#include <iomanip>
using namespace std;

//constructor 
template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &info){
	data = info;
	next = 0;
}
//get data returns the data from the linked list
template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const{
	return data;
}
#endif
