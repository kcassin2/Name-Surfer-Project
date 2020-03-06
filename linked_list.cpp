#ifndef LIST_CPP
#define LIST_CPP
#include "linked_list.h"
#include <iostream>
#include <string>
using namespace std;

template <class NODETYPE>
linked_list<NODETYPE>::linked_list() {
	first = NULL;
	current = NULL;
	last = NULL;
}

template <class NODETYPE>
linked_list<NODETYPE>::~linked_list() {
	current = first;
	while (current != NULL) {
		first = first->next;
		delete current;
		current = first;
	}
	current = last = first = NULL;
}
template <class NODETYPE>
linked_list<NODETYPE>::linked_list(linked_list<NODETYPE> &originalList) {
	//Fill in the copy constructor
}

//here is where inside of the linked list the values will be listed in order from the rear forward
	template <class NODETYPE>
bool linked_list<NODETYPE>::InsertInOrder(NODETYPE value)
{
    //cout<<"Insert in order\n";
	ListNode<NODETYPE>*temp;
	temp=new ListNode<NODETYPE>;

	if(temp==nullptr){

		return false;

	}
    temp->data = value;
	if(first==nullptr){
	   // cout<<"Inserting in the linked list\n";
		InsertRear(value);
	}
	else if(temp->data<first->data){
	    //cout<<"Front\n";
		InsertFront(value);
	}
	else if(temp->data > last->data){
	    //cout<<"Back\n";
		InsertRear(value);
	}
	else{
	    //cout<<"Middle\n";
		current=first;
		while(current!=nullptr && current->next->data<value){
			current=current->next;
		}
		temp->next = current->next;
		current->next = temp;
		
	}

	if(first ==  nullptr)
	   // cout<<"List is empty\n";
	return true;
}
//here is a function to insert the values to the front of the linked list
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertFront(NODETYPE value) {
	current = new ListNode<NODETYPE>;
	if(current== nullptr){
		return false;
	}
	else{ 
		current-> data= value;
	}
	if(first==nullptr){
		first=current;
		last=current;
		current->next= nullptr;
		return true;
	}
	else{
		current->next=first;
		first=current;
		return true;

	}

	
}
//here is a function to insert the values to the back of the linked list
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertRear(NODETYPE value) {
	current = new ListNode<NODETYPE>;
	if(current==nullptr){
		return false;
	}
	else{
		current->data=value;

	}
	if(first==nullptr){
	    //cout<<"Inserting first node\n";
		first=current;
		last=current;
		current->next=nullptr;
		return true;


	}
	else{
		last->next=current;
		current->next=nullptr;
		last=current;
		return true;
}

}
//this checks if the linked list is empty
template <class NODETYPE>
bool linked_list<NODETYPE>::IsEmpty() const {
	return (first == NULL);
}
// this is used to search the baby names and their years in the files

template <class NODETYPE>
bool linked_list<NODETYPE>::Search(NODETYPE &value) {

	if(IsEmpty()){
		return false;
	}
	else{

		current=first;
		while(current!=nullptr && current->data!=value){
			current= current->next;

		}
		if(current==nullptr){
			return false;
		}
		else
		{
		    value=current->data;
			return true;
		}
	}
}

//this prints all of the values inside of the linked list
template <class NODETYPE>
void linked_list<NODETYPE>::PrintAll() {
//	if(!IsEmpty())
{
    	if(first ==  nullptr)
	       // cout<<"List is empty\n";
		current=first; 
		while(current!=nullptr){
			cout<<current->data<<endl;
			current=current->next;
		}
	}
	

}
//this is used to remove a value from the front of the linked list
template <class NODETYPE>
bool linked_list<NODETYPE>::RemoveFront(NODETYPE & value) {
	if(first->data==value){
		value=first->data;
		current=first->next;
		delete first;
		first=current;
		return true; 
	}
}
//this is used to remove a value from the back of the linked list
template <class NODETYPE>
bool linked_list<NODETYPE>::RemoveRear(NODETYPE & value) {
	if(last->data== value){
		current=first; 
		while(current->next!=last){
			current=current->next;

		}
	}
	value=last->data;
	delete last;
	last=current;
	last->next=nullptr;
	return true;


}
//this is to remove a value from a linked list at a given location
template <class NODETYPE>
bool linked_list<NODETYPE>::Remove(NODETYPE & value) {
	ListNode<NODETYPE>*temp;

	if(value==first->data && first==last){
		value = first->data;
		delete first;
		current=last;
		first=nullptr;


	}
	else if(value==first->data){
		value=first->data;
		current=first;
		first=first->next;
		delete current;

	}

	else if(value == last->data){
		value = last->data;
		current=first;
		while(current->next!=last){
			current=current->next;

		}
		delete last; 
		last=current;
		current->next=nullptr;

	}
	else{
		current=first;
		while(current!=nullptr && current->next->data!= value){
			return true;
		}
    	if(current==nullptr){
    		return false;
    	}
    	else{
    		temp= current;
    		value=temp->data;
    		current->next= temp->next;
    		delete temp;
    	}
	}
	return true;




}

#endif