/*
	Title:      DynStack.h
	Author:     Joey Borrelli
	Date:       3/3/Anno Domini 2024
    Per Ipsum, et cum Ipso, et in Ipso, est tibi Deo Patri omnipotenti, in unitate Spiritus Sancti, omnis honor et gloria per omnia saecula saeculorum.
*/

#ifndef DYNSTACK_H
#define DYNSTACK_H

#include <iostream>

template <typename obj>
class DynStack{
    private:
        struct DynStackNode{
            obj value;
            DynStackNode* next;
        };

        DynStackNode* top;
        
    public:
        DynStack();
        ~DynStack();
        void push(obj);
        void pop(obj &);
        bool isEmpty();
};

template <typename obj>
DynStack<obj>::DynStack(){
    top = NULL;
}

template <typename obj>
DynStack<obj>::~DynStack(){
    DynStackNode* nodePointer;
    DynStackNode* nextNodePointer;

    nodePointer = top;

    while(nodePointer != NULL){
        nextNodePointer = nodePointer->next;
        delete nodePointer;
        nodePointer = nextNodePointer;
    }
}

template <typename obj>
void DynStack<obj>::push(obj myObject){
    DynStackNode* newNodePointer = NULL;

    newNodePointer = new DynStackNode;
    newNodePointer->value = myObject;

    if(isEmpty()){
        top = newNodePointer;
        newNodePointer->next = NULL;
    }else{
        newNodePointer->next = top;
        top = newNodePointer;
    }
}

template <typename obj>
void DynStack<obj>::pop(obj &myObject){
    DynStackNode* tempNode = NULL;

    if(isEmpty()){
        std::cout << "The stack is empty.\n";
    }else{
        myObject = top->value;
        tempNode = top->next;
        delete top;
        top = tempNode;
    }
}

template <typename obj>
bool DynStack<obj>::isEmpty(){
    return(!top);
}

#endif