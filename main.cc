
#include <iostream>
#include "int-dl-list.h"

using namespace std;

int main()
{
	// declaring variables for different menus and options
	int menu, menu1, menu2, menu3, menu4, insert;
	// Base menu
	while(menu!=5)
	{
	cout << "(1) Create Simple (Unsorted) List" << endl;
	cout << "(2) Create Sorted List" << endl;	
	cout << "(3) Create Queue (FIFO)" << endl;	
	cout << "(4) Create Stack (LIFO)" << endl;
	cout << "(5) Exit program" << endl;	
	cin >> menu;
	switch (menu) {

		case 1 : {  // Unsorited List Menu
			IntDLList list;
			while(menu1!=7) {
			cout << "(1) Enter integer for insertion at head of list" << endl;
			cout << "(2) Enter integer for insertion at tail of list" << endl;
			cout << "(3) Display and delete integer from head of list" << endl;
			cout << "(4) Display and delete integer from tail of list" << endl;
			cout << "(5) Search for integer in list, and delete that node" << endl;
			cout << "(6) Display contents of list from head to tail, in order" << endl;
			cout << "(7) Exit program" << endl;	
			cin >> menu1;	
			switch (menu1) {
				case 1 :
					cout << "Please enter an integer for insertion" << endl;
					cin >> insert;
					list.addToHead(insert);
					break;
				case 2 :
					cout << "Please enter an integer for insertion" << endl;
					cin >> insert;
					list.addToTail(insert);
					break;
				case 3 :
					cout << "The value in the deleted head is " << list.deleteFromHead() << endl;
					break;
				case 4 :
					cout << "The value in the deleted tail is " << list.deleteFromTail() << endl;
					break;
				case 5 :
					cout << "Please enter an integer to delete from list" <<  endl;
					cin >> insert;
					list.deleteNode (insert);
					break;
				case 6 :
					list.printlist();
					break;	
				default :
					break;
			}
			}	
			break; 		 		
		}
		case 2 : { // Sorted List Menu
			IntDLList slist;
			while(menu2!=4) {
			cout << "(1) Enter integer for sorted insertion (increasing order) into list" << endl;
			cout << "(2) Search and delete integer, if present in list" << endl;
			cout << "(3) Display contents of sorted list of integers, in increasing order" << endl;
			cout << "(4) Exit program" << endl;	
			cin >> menu2;	
			switch(menu2) {
				case 1 : 
					cout << "Please enter an integer for sorted insertion" << endl;
					cin >> insert;
					slist.addSorted(insert);
					break;
				case 2 :
					cout << "Please enter an integer to be deleted" << endl;
					cin >> insert;
					slist.deleteNode(insert);
					break;
				case 3 :
					slist.printlist();
					break;
				default :
					break;
			}
			}	
		break;
		}

		case 3 : { // Que Menu
			IntDLList qlist;
			while(menu3!=4) {
			cout << "(1) ENQUEUE (Enter integer for insertion into queue)" << endl;	
			cout << "(2) DEQUEUE (Display and delete integer from queue)" << endl;
			cout << "(3) PRINT QUEUE (Display queue contents without deleting anything, first element first)" << endl;
			cout << "(4) Exit program" << endl;	
			cin >> menu3;
			switch(menu3) {
				case 1 :
					cout << "Please enter an integer for insertion" << endl;
					cin >> insert;
					qlist.addToTail(insert);
					break;
				case 2 :
					cout << "The value deleted from the que was " << qlist.deleteFromHead() << endl;
					break;
				case 3 :
					qlist.printlist();
					break;
				default :
					break;
			}
			}
				break;
		}
		case 4 : // Stack Menu
			IntDLList stlist;
			while(menu4!=4) {
			cout << "(1) PUSH (Enter integer for insertion into stack)" << endl;
			cout << "(2) POP (Display integer and delete it from stack)" << endl;
			cout << "(3) PRINT STACK (Display stack contents without deleting anything, bottom element first)" << endl;
			cout << "(4) Exit program" << endl;	
			cin >> menu4;
			switch(menu4) {
				case 1 :
					cout << "Please enter an integer for insertion" << endl;
					cin >> insert;
					stlist.addToTail(insert);
					break;
				case 2 :
					cout << "The value deleted from the stack was " << stlist.deleteFromTail() << endl;
					break;
				case 3 :
					stlist.printlist();
					break;
				default :
					break;
			}
			}	
			break;
	}	
	}	
	return 0;
}

