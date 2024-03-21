/*
	Title:      BinaryTree.h
	Author:     Joey Borrelli
	Date:       3/21/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#ifndef BINARYTREE_H
#define BINARYTREE_H

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

        void insert(){
            /*TODO: WRITE*/
        }

        void destroySubTree(){
            /*TODO: WRITE*/
        }

        void displayInOrder(){
            /*TODO: WRITE*/
        }

    public:
        BinaryTree();
        ~BinaryTree();
        void insertNode(obj);
        void displayInOrder();
        bool searchNode(obj);
};

template <typename obj>
BinaryTree<obj>::BinaryTree(){
    /*TODO: WRITE*/
}

template <typename obj>
BinaryTree<obj>::~BinaryTree(){
    /*TODO: WRITE*/
    // should call destroySubTree
}

template <typename obj>
void BinaryTree<obj>::insertNode(obj value){
    /*TODO: WRITE*/
}

template <typename obj>
void BinaryTree<obj>::displayInOrder(){
    /*TODO: WRITE*/
    // should call the displayInOrder private function
}

template <typename obj>
bool BinaryTree<obj>::searchNode(obj value){
    /*TODO: WRITE*/
    // return true if node is found
}

#endif