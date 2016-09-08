#ifndef _INT_DL_LIST_H_
#define _INT_DL_LIST_H_
#include "int-dll-node.h"

class IntDLList
{
public:
	IntDLList();
	~IntDLList();
	int isEmpty();
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead(); //delete head and return its info
	int deleteFromTail(); //delete tail and return its info
	void deleteNode(int);
	bool isInList(int) const;
	void printlist();
	void addSorted(int i);

protected:
private:
IntDLLNode *head, *tail;
};

#endif // _INT_DL_LIST_H_

