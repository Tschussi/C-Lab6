
#include "int-dll-node.h"

IntDLLNode::IntDLLNode(int el, IntDLLNode *n, IntDLLNode *p)
{
	info = el;
	next = n;
	prev = p;
}

