/*
	Title:      LinkedList.h
	Author:     Joey Borrelli
	Date:       2/18/2024
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Destination.h"

class LinkedList{
    private:
        struct ListNode{
            // template value;
            ListNode* next;
        };

        ListNode* head;
        ListNode* tail;
        int numNodes;
        
    public:
        LinkedList();
        ~LinkedList();
        int getLength();
        //template getNodeValue(int pos);
        void insertNode(Destination* nodeVal);
};

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    numNodes = 0;
}

LinkedList::~LinkedList(){
    while(head){ // while our first value isn't null
        // create a node to delete that is our first value
        ListNode* nodeToDelete = head;
        // set our first value to the next value
        head = nodeToDelete->next;
        // delete our last value
        delete nodeToDelete;
    }
}

int LinkedList::getLength(){
    return numNodes;
}

//template LinkedList::getNodeValue(int pos){
//
//}

void LinkedList::insertNode(Destination* nodeVal){
    // Dynamically allocate a new node with the value sent to this function.
    ListNode* newNode = new ListNode();

    // If no nodes are in the list, insert the node as the head & tail.
    if(!head){
        head = newNode;
        tail = newNode;
    }else if(newNode->value >= tail->value){ // If the Destination name alphabetically goes after tail’s destination name, then insert this new node at the end of the linked list.
        tail->next = newNode;
        tail = newNode;
    }else{ // Otherwise, you will traverse through the linked list to find the appropriate spot to insert the node so that the name is alphabetically in order.*/
        // create a nodePtr to use to traverse the list.
        ListNode* traversingNode = new ListNode();
        
        while(traversingNode){// while traversing node isn't on the last value

        }
    }

    
}


#endif