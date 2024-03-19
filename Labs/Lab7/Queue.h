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
            QueueNode* next = nullptr;
        };

        int numNodes;
        QueueNode* head;
        QueueNode* tail;
    public:
        Queue();
        ~Queue();
        void enqueue(std::string);
        void dequeue();
        int getNumNodes();
        bool isEmpty();
};

Queue::Queue(){
    head = nullptr;
    tail = nullptr;
    numNodes = 0;
}

Queue::~Queue(){
    /*NEEDS TO LOOP THROUGH QUEUE*/
    std::cout << "Oh shoot, I am sorry, our park is closed so " + head->riderName + "will not get to ride today.\n";
}

void Queue::enqueue(std::string riderName){
    QueueNode *newNode;
    newNode->riderName = riderName;
    
    if(isEmpty){
        this->head = newNode;
        this->tail = newNode;
    }else{
        
    }
}

void Queue::dequeue(){

}

int Queue::getNumNodes(){
    return(numNodes);
}

bool Queue::isEmpty(){
    return(!head);
}


#endif