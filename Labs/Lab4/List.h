/*
	Title:      List.h
	Author:     Joey Borrelli
	Date:       2/17/2024
*/

#ifndef LIST_H
#define LIST_H
using namespace std;

class List{
    private:
        struct ListNode{
            string monster;
            ListNode* next;

            ListNode(string value){
                monster = value;
                next = NULL;
            }
        };

        ListNode* head;
        ListNode* tail;
    public:
        List();
        ~List();
        void appendNode(string value);
        void insertNode(string value);
        void deleteNode(string value);
        void displayList();
};

List::List(){
    cout << "The linked list has been created.";
    head = NULL;
    tail = NULL;
}

List::~List(){
    while(head){ // while our first value isn't null
        // create a node to delete that is our first value
        ListNode* nodeToDelete = head;
        // set our first value to the next value
        head = nodeToDelete->next;
        // delete our last value
        delete nodeToDelete;
    }
    cout << "\nAll list nodes have been removed.\n";
}

void List::appendNode(string value){
    // dynamically allocate a new ListNode and set the ListNode’s value to the string sent to this function
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


void List::insertNode(string value){
    // dynamically allocate a new ListNode and set the ListNode’s value to the string sent to this function
    ListNode* newNode = new ListNode(value);

    /* place the new node in the linked list alphabetically based on the string values. */
    ListNode* traversingNodePtr; // create a pointer to traverse my list
    ListNode* prevNodePtr; // create a pointer to hold my previous traversingNodePtr
    
    if(head){ // if my list isn't empty, NULL evaluates to false
        
        // set my traversingNodePointer to the start of the list.
        traversingNodePtr = head; 
        prevNodePtr = head;
        
        while(traversingNodePtr){ // while not on the end NULL value
            
            if(traversingNodePtr->monster >= value){ // if the current node is bigger alphabetically than the newNode
                
                // set the new node's nextPtr to the current node
                newNode->next = traversingNodePtr;

                // set the previous node's nextPtr to the newNode
                prevNodePtr->next = newNode;
                
                return; // kick us out so we don't set newNode to the end
            }
            
            // set prev node to my traversing Node
            prevNodePtr = traversingNodePtr;
            
            // set traversingNode to next pointer
            traversingNodePtr = traversingNodePtr->next; 
        }

        // if our if on line 88 isn't tripped, then we never return and bellow is executed
        // inserts newNode to the end
        tail->next = newNode;
        tail = newNode;
    
    }else{ // if the list is empty
        // set this new node as the first node
        head = newNode;
        tail = newNode;
    }
}

// traverse the linked list to search for a node with the same value and delete it when found
void List::deleteNode(string value){
    // create a pointer to traverse my list
    ListNode* traversingNodePtr; 
    // create a pointer to hold my previous traversingNodePtr
    ListNode* prevNodePtr;

    if(head){ // if my list isn't empty, NULL evaluates to false
        // set my traversingNodePointer and previousNodePointer to the start of the list.
        traversingNodePtr = head; 
        prevNodePtr = head;

        // traverse list:
        while(traversingNodePtr){ // while not on the end NULL value
            
            if(traversingNodePtr->monster == value){ // if our traversing node matches the value
                
                if(head == traversingNodePtr){ // if our matched value is the first value
                    // set the head to the next link
                    head = traversingNodePtr->next;
                    // delete the node
                    delete traversingNodePtr;
                    // kick out of the function
                    return;
                }else if(tail == traversingNodePtr){ // if our matched value is the last value
                    // set the tail to the previous link
                    tail = prevNodePtr;
                    // set the previous node's next to null
                    prevNodePtr->next = NULL;
                    // delete the node
                    delete traversingNodePtr;
                    // kick out of the function
                    return;
                }else{ // if our matched value is in the middle of the list
                    // set our previous node to point to the next next node
                    prevNodePtr->next = traversingNodePtr->next;
                    // delete our node that matches.
                    delete traversingNodePtr;
                    // kick out of the function
                    return;
                }
            }

            // set prev node to my traversing Node
            prevNodePtr = traversingNodePtr;
            
            // set traversingNode to next pointer
            traversingNodePtr = traversingNodePtr->next;
        }
    }else{
        cout << "\nERROR: No nodes detected to delete\n";
    }
}

// display each node’s value in order from head to tail
void List::displayList(){
    // create a pointer to traverse my list
    ListNode* traversingNodePtr;

    if(head){ // if my list isn't empty, NULL evaluates to false
        traversingNodePtr = head; // set my traversingNodePointer to the start of the list.
        
        while(traversingNodePtr){ // while we aren't on the last value which evaluates to NULL/false.
            cout << traversingNodePtr->monster << endl;
            // set traversingNode to next pointer
            traversingNodePtr = traversingNodePtr->next;
        }
    }else{
        cout << "\nERROR: No nodes detected to print\n";
    }
}

#endif