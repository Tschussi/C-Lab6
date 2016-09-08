#include "int-dl-list.h"
const int EMPTY_LIST = 1;
#include <iostream>

IntDLList::IntDLList() {
	head = tail = NULL;
}

IntDLList::~IntDLList() {
	for (IntDLLNode *p; !isEmpty(); ) {
		p = head->next;
		delete head;
		head = p;
		}
	}

int IntDLList::isEmpty() {
	return (head == NULL);
}

void IntDLList::addToHead(int el) {
	if (tail == NULL)
		head = tail = new IntDLLNode(el);
	else {
		head = new IntDLLNode(el,head, NULL);
		head->next->prev = head;
	}
	}

void IntDLList::addToTail(int el) {
	if (tail != NULL) { 
		tail = new IntDLLNode(el, NULL, tail);
		tail->prev->next = tail;
		}
	else 
		head = tail = new IntDLLNode(el);
	}

int IntDLList::deleteFromHead() {
	if(!isEmpty())
	{
		int el = head->info;
		if (head == tail) // if only 1 node in list
			{head = tail = NULL;}
		else {
			head = head->next;
			delete head->prev;
			head->prev = NULL; 
			}
		return (el);
	}
	else throw(EMPTY_LIST);
}


int IntDLList::deleteFromTail() {
	if(head!=NULL)
	{
		int el = tail->info;
		if (head == tail) { // if only 1 node in list
			delete tail;
			head = tail = NULL;
		}
	else { 
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
	}
	return (el);
	}
	else throw(EMPTY_LIST);
}


void IntDLList::deleteNode(int el) {
	if (head != NULL) // if nonempty list
		if (head == tail && el == head->info) { // if only 1 node is in list
			delete head;
			head = tail = NULL;
		}
		else if (el == head->info) {  // if more than 1 node is in list
			IntDLLNode *tmp = head; // and if el is stored in head node
			head = head->next; // then advance the head ptr
			delete tmp; // and delete the old head node
	}
	else { // if more than 1 node is in list, and element is in non­head node
		IntDLLNode *pred, *tmp;
		for (pred = head, tmp = head->next;
			tmp != NULL && tmp->info != el;
			pred = pred->next, tmp = tmp->next); // end of for
				if (tmp != NULL) {  // that is, tmp­>info != el is false
					pred->next = tmp->next;
				if (tmp == tail)
					tail = pred;
				delete tmp; // and delete non­head node
		}
	}
}

bool IntDLList::isInList(int el) const { // checks if an info value is in the list
	IntDLLNode *tmp;
	for (tmp = head; tmp != NULL && tmp->info != el; tmp = tmp->next);
		return (tmp != NULL);
}

void IntDLList::printlist() { // Prints all nodes of a list 
	for(IntDLLNode *tmp = head; tmp!=NULL; tmp=tmp->next) {
		std::cout << tmp->info << " ";
	}
	std::cout << std::endl;
	}

void IntDLList::addSorted(int i) { // Sorts a new node into a Sorted list
	IntDLLNode *node = new IntDLLNode(i);
	IntDLLNode *tmp;
	if(head==NULL) { // empty list
		head = tail = node;
		return; }
	if(head->info >= i) { // if smallest term
		node->next = head;
		head->prev = node;
		head = node;
		return; }
	for(tmp = head; tmp->next != NULL && tmp->next->info < i; tmp = tmp->next);
	if(tmp->next == NULL) { // if largest term
		tmp->next = node;
		node->prev = tail;
		node->next = NULL;
		tail = node;
		return; }
	else { // if somewhere in list
		node->next = tmp->next;
		node->prev = tmp;
		tmp->next = node;
		return; }
	}