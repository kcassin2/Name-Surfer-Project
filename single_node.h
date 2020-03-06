#ifndef NODE
#define NODE
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <ios>
#include <iomanip>
using namespace std;



template <class NODETYPE> class linked_list;

template <class NODETYPE>
class ListNode{
	friend class linked_list<NODETYPE>;
public:
	ListNode() { next = 0; }
	ListNode(const NODETYPE &);
	NODETYPE getData() const;
private:
	NODETYPE data;
	ListNode <NODETYPE>*next;
};
#include "single_node.cpp"

#endif