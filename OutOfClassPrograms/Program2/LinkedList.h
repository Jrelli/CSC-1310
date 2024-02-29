/*
	Title:      LinkedList.h
	Author:     Joey Borrelli
	Date:       2/18-29/Anno Domini 2024
    Per Ipsum, et cum Ipso, et in Ipso, est tibi Deo Patri omnipotenti, in unitate Spiritus Sancti, omnis honor et gloria per omnia saecula saeculorum.
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Destination.h"
#include <iostream>

template <typename obj>
class LinkedList{
    private:
        // structure of our nodes
        struct ListNode{
            obj value; // holds our node value
            ListNode* next; // points to the next node
        };

        ListNode* head; // points to the first node
        ListNode* tail; // points to the last node
        int numNodes; // holds the number of nodes in the linked list
        
    public:
        LinkedList(); // constructor
        ~LinkedList(); // destructor
        int getLength(); // getter
        obj getNodeValue(int desiredPos); // getter
        void insertNode(Destination* nodeVal); // setter
};

// initialize head, tail, & numNodes
template <typename obj>
LinkedList<obj>::LinkedList(){
    head = nullptr;
    tail = nullptr;
    numNodes = 0;
}

// deletes all nodes in the list
template <typename obj>
LinkedList<obj>::~LinkedList(){
    while(head){ // while our first value isn't null (which would mean the list is empty)
        // create a node to delete that is our first value
        ListNode* nodeToDelete = head;
        // set our first value to the next value
        head = nodeToDelete->next;
        // delete our last value
        delete nodeToDelete;
    }
}

// return the number of nodes currently in the linked list
template <typename obj>
int LinkedList<obj>::getLength(){
    return numNodes;
}

// accepts an integer indicating the position in the linked list and will return the value in the node at that position 
template <typename obj>
obj LinkedList<obj>::getNodeValue(int desiredPos){
    if(desiredPos > numNodes){
        std::cout << "ERROR: Position does not exist. There are only " << numNodes << " nodes.\n";
        return;
    }else{
        /* NOTE: MAY NEED TO CHANGE TO ONE DEPENDING ON HOW INPUT IS DONE RETURN TO THIS!!! */
        int currentNodePos = 0; // holds our current position 
        ListNode* traversingNodePointer = head; // Node that we are going to use to increment through the linked list and find our value.

        while(traversingNodePointer){ // while we aren't at the end of the list (NULL)
            if(desiredPos == currentNodePos){ // if we are at our desired node
                return(traversingNodePointer->value); // return the value
            }
            currentNodePos++; // increments our currentNodePosition
            traversingNodePointer = traversingNodePointer->next; // sets our TNP to the next node in the linked list.
        }
    }
}

// This function inserts a new node into the linked list in alphabetical order according to its value.
template <typename obj>
void LinkedList<obj>::insertNode(Destination* nodeVal){
    // Dynamically allocate a new node with the value sent to this function.
    ListNode* newNode = new ListNode();
    newNode->value = nodeVal;

    // If no nodes are in the list, insert the node as the head & tail.
    if(!head){
        head = newNode;
        tail = newNode;
        return;
    }else if(newNode->value >= tail->value){ // If the Destination name alphabetically goes after tail’s destination name, then insert this new node at the end of the linked list.
        tail->next = newNode;
        tail = newNode;
        return;
    }else{ // Otherwise, you will traverse through the linked list to find the appropriate spot to insert the node so that the name is alphabetically in order.*/
        // create a nodePtr to use to traverse the list.
        ListNode* traversingNodePointer = head;
        ListNode* prevNodePointer = head;
        
        while(traversingNodePointer){ // while traversing node isn't on the last value
            if(newNode->value < traversingNodePointer->value){ // if our newNode's value should go before our traversing node.
                prevNodePointer->next = newNode; // set the previous node's next to the new node 
                newNode->next = traversingNodePointer; // the the new nodes next to the traversing node.
                return;
            }
            prevNodePointer = traversingNodePointer; // set our previous node to the current traversing Node
            traversingNodePointer = traversingNodePointer->next; // set our traversing node to our next value
        }
    }
}

#endif