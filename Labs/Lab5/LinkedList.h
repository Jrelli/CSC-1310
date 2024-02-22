/*****************************************************************
	Filename:       LinkedList.h - Class Specification File for 
				    LinkedList Template Class
	Date Created:   2/21/A.D.2024
	Author:         Joey Borrelli
	Purpose:        LAB 5 - A Singly-Linked List implemented in a
				    LinkedList template class that contains a ListNode
				    structure variable
******************************************************************/

#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
using namespace std;


template <typename T>
class LinkedList
{
	private:
		struct ListNode
		{
			//STRUCTURE MEMBERS NEED TO BE ADDED HERE
			T nodeValue;
			ListNode* next;

			ListNode(T NV){
				nodeValue = NV;
				next = NULL;
			}
		}; 

		ListNode *head;	
		ListNode *tail;		

	public:
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}
		~LinkedList();
		void appendNode(T value);
		void deleteNode(int position);
		void displayList() const;
};

//DEFINE ALL OTHER LinkedList class FUNCTIONS BELOW THIS LINE--------------------------------

template <typename T>
LinkedList<T>::~LinkedList(){
	/* Delete all nodes that remain in the linked list*/
	while(head){ // while our first value isn't null
        // create a node to delete that is our first value
        ListNode* nodeToDelete = head;
        // set our first value to the next value
        head = nodeToDelete->next;
        cout << "*****DELETING the node with address: " << nodeToDelete << endl;
		// delete our last value
        delete nodeToDelete;
    }
}

template <typename T> 
void LinkedList<T>::appendNode(T value){
	// dynamically allocate a new ListNode and set the ListNode’s value to the value sent to this function
	ListNode* newNode = new ListNode(value); 

	// place the new node at the end of the linked list (use the tail pointer to help!)
	if(!head){ // if my list is empty, NULL evaluates to false
        // set this new node as the first node
        head = newNode;
        tail = newNode;
    }else{ // if there are already nodes in the list
        // set the current lastNode's next pointer to the newNode that will be appended. 
        tail->next = newNode;

        // set the tail to point to the newNode that will be appended.
        tail = newNode;
    }
}


template <typename T>
void LinkedList<T>::deleteNode(int pos){
	// If the linked list is empty, stop this function from running
	if(!head){
		return;
	}

	// If the position sent to this function is zero
	if(pos == 0){
		cout << "-----DELETING the node with address: " << head << endl;
		ListNode* tempNode = head;
		head = tempNode->next;
		// delete the head node
		delete tempNode;
	}else{ // Otherwise,   
		ListNode* traversingNodePtr = head;
		ListNode* prevNodePtr = head;
		int currentPos = 1;
		
		// traverse the linked list to search for a node at the given position (if it exists)
		while(traversingNodePtr){
			// if the positions match
			if(currentPos = pos){
				if(tail == traversingNodePtr){ // if our matched value is the last value
					cout << "-----DELETING the node with address: " << traversingNodePtr << endl;
            	    // set the tail to the previous link
                    tail = prevNodePtr;
                    // set the previous node's next to null
                    prevNodePtr->next = NULL;
                    // and delete it.
                    delete traversingNodePtr;
                }else{ // if our matched value is in the middle of the list
					cout << "-----DELETING the node with address: " << traversingNodePtr << endl;
                    // set our previous node to point to the next next node
                    prevNodePtr->next = traversingNodePtr->next;
                    // and delete it.
                    delete traversingNodePtr;
                }
			}
			
			prevNodePtr = traversingNodePtr;
			// set traversingNode to next pointer
            traversingNodePtr = traversingNodePtr->next;
			// increases the position by 1
			currentPos++;
		}
	}
}

template <typename T>
void LinkedList<T>::displayList() const{
	if(!head){
		cout << "There are no nodes in the list\n";
		return;
	}else{ // Otherwise, traverse the linked list and print out each node
		ListNode* traversingNodePtr = head;
		int currentPos = 1;
		while(traversingNodePtr){
			cout << "-----Node " << currentPos << " with memory address " << traversingNodePtr << endl;
			// traversingNodePtr->
			// print out pickle 
			// Pickle(cout, traversingNodePtr->nodeValue);

			currentPos++;
			// set traversingNode to next pointer
            traversingNodePtr = traversingNodePtr->next;
		}
	}
}

#endif