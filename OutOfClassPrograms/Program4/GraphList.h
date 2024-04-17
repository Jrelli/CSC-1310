/*
	Title:      GraphList.h
	Author:     Joey Borrelli
	Date:       4/17/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

class GraphList{
    private:
        struct ListNode{
            int value;
            ListNode* next;
            /*CHECK*/
            ListNode(int value){
                this->value = value;
                this->next = nullptr;
            }
        };
        ListNode** headArray; // array of linked lists
        int numVertices;
        int numEdges;
    public:
        GraphList(int);
        ~GraphList();
        void addEdge(int, int);
        void printGraph();
};

/*TODO*/
GraphList::GraphList(int numVertices){
    this->numVertices = numVertices;
    // dynamically allocate an array of pointers to ListNodes
}

/*TODO*/
GraphList::~GraphList(){
    // deletes linked lists
}

/*TODO*/
void GraphList::addEdge(int x, int y){
    ListNode newNode(x);
    // add node to linked list
}

/*TODO*/
void GraphList::printGraph(){

}

#endif