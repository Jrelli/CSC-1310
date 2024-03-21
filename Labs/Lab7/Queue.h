/*
	Title:      Queue.h
	Author:     Joey Borrelli
	Date:       3/19/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <iostream>

class Queue{
    private:
        struct QueueNode{
            std::string riderName;
            QueueNode* next; // points to next node

            QueueNode(std::string riderName){
                next = nullptr;
                this->riderName = riderName;
            }
        };

        int numNodes; // total nodes
        QueueNode* head; // front of the line
        QueueNode* tail; // back of the line
    public:
        /*Function prototypes*/
        Queue();
        ~Queue();
        void enqueue(std::string);
        std::string dequeue();
        int getNumNodes();
        bool isEmpty();
        QueueNode* getDesiredNode(int);
};

Queue::Queue(){
    // init all zero/null
    this->head = nullptr;
    this->tail = nullptr;
    this->numNodes = 0;
}

Queue::~Queue(){
    while(head){ // while there are nodes in queue
        QueueNode* nodeToDelete = this->head; // set node to first in line
        
        std::cout << "Oh shoot, I am sorry, our park is closed so " + nodeToDelete->riderName + " will not get to ride today.\n";
        
        // set our head to the next in line
        this->head = this->head->next;

        // delete previous head
        delete nodeToDelete;
    }
}

void Queue::enqueue(std::string riderName){
    // create node
    QueueNode* newNode = new QueueNode(riderName);

    // insert into queue
    if(isEmpty()){ // if there is nothing in the queue
        this->head = newNode;
        this->tail = newNode;
    }else{ // if we need to add the dude to the end of the queue
        QueueNode* previousNode = getDesiredNode(getNumNodes() - 1);
        previousNode->next = newNode;
        this->tail = newNode;
    }

    // incr total
    this->numNodes++;
}

std::string Queue::dequeue(){
    // find our node to return
    QueueNode* nodeToReturn = this->head;
    
    // set our head to the next in line
    this->head = this->head->next;

    // decrement our total 
    this->numNodes--;

    // return our rider's name
    return(nodeToReturn->riderName);
}

// returns the total number of nodes
int Queue::getNumNodes(){
    return(numNodes);
}

// returns if our queue are empty or not
bool Queue::isEmpty(){
    return(!head);
}

// returns a pointer to a node at our desired position. (first index is 0)
Queue::QueueNode* Queue::getDesiredNode(int desiredNodePos){
    QueueNode* tempNode = head;
    // loop through function, search for match and return node
    for(int i = 0; i <= getNumNodes(); i++){ 
        if(i == desiredNodePos){
            return(tempNode);
        }else{
            tempNode = tempNode->next; // set tempNode to next in queue
        }
    }
}

#endif