#ifndef _INT_DLL_NODE_H_
#define _INT_DLL_NODE_H_
#define NULL 0

class IntDLLNode
{
	friend class IntDLList;
public: 
	IntDLLNode(int el=0, IntDLLNode *n=NULL, IntDLLNode *p=NULL);
		
protected:
int info; // int type data member
IntDLLNode *next, *prev; // pointer type data member

private:

};

#endif // _INT_DLL_NODE_H_

