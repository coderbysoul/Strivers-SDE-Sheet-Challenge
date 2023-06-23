//https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_8230742?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {
    pair<int, int> result;
    BinaryTreeNode<int>* curr = root;
    BinaryTreeNode<int>* pred = NULL;
    BinaryTreeNode<int>* succ = NULL;

    while (curr != NULL) {
        if (curr->data == key) {
            if (curr->left != NULL) {
                pred = curr->left;
                while (pred->right != NULL) {
                    pred = pred->right;
                }
            }
            if (curr->right != NULL) {
                succ = curr->right;
                while (succ->left != NULL) {
                    succ = succ->left;
                }
            }
            break;
        } else if (curr->data > key) {
            succ = curr;
            curr = curr->left;
        } else {
            pred = curr;
            curr = curr->right;
        }
    }

    result.first = (pred != NULL) ? pred->data : -1;
    result.second = (succ != NULL) ? succ->data : -1;

    return result;
}

