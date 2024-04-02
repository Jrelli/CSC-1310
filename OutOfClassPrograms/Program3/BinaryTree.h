/*
	Title:      BinaryTree.h
	Author:     Joey Borrelli
	Date:       3/21/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

template <typename obj>
class BinaryTree{
    private:
        struct TreeNode{
            obj value;
            TreeNode* left;
            TreeNode* right;
            TreeNode(obj value){
                this->value = value;
                this->left = nullptr;
                this->right = nullptr;
            }
        };

        TreeNode* root;

        void insert(TreeNode* &nodePtr, TreeNode* &newNode){
            if(!nodePtr){ // if the node is empty, insert
                nodePtr = newNode;
            }else if(newNode->value < nodePtr->value){ // if the new node is less than previous, move left.
                insert(nodePtr->left, newNode);
            }else{ // if the new node is greater than previous, then move right.
                insert(nodePtr->right, newNode);
            }
        }

        void destroySubTree(TreeNode* nodePtr){
            if(nodePtr){ // if the pointer isn't empty
                if(nodePtr->left){ // if there is a pointer on the left
                    destroySubTree(nodePtr->left);
                }
                if(nodePtr->right){
                    destroySubTree(nodePtr->right);
                }
                delete nodePtr;
            }
        }

        // recursive function that will print out each node in order 
        void displayInOrder(TreeNode* nodePtr){
            if(nodePtr){ // if there is a value.
                displayInOrder(nodePtr->left);
                std::cout << "Pokemon Index Number: " << nodePtr->value.getID() << "       Name: " << nodePtr->value.getName() << std::endl;
                displayInOrder(nodePtr->right);
            }
        }

    public:
        BinaryTree();
        ~BinaryTree();
        void insertNode(obj*);
        void displayInOrder();
        bool searchNode(obj*);
};

template <typename obj>
BinaryTree<obj>::BinaryTree(){
    root = nullptr;
}

template <typename obj>
BinaryTree<obj>::~BinaryTree(){
    this->destroySubTree(root);
}

template <typename obj>
void BinaryTree<obj>::insertNode(obj* value){
    TreeNode* newNode = new TreeNode(*value);

    this->insert(root, newNode);
}

template <typename obj>
void BinaryTree<obj>::displayInOrder(){
    // calls the displayInOrder private function, sending the root
    displayInOrder(root);
}

template <typename obj>
bool BinaryTree<obj>::searchNode(obj* value){
    TreeNode* nodePtr = root;

    while (nodePtr){
        if(nodePtr->value == *value){
            return true;
        }else if(*value < nodePtr->value){
            nodePtr = nodePtr->left;
        }else{
            nodePtr = nodePtr->right;
        }
    }
    return false;
}

#endif