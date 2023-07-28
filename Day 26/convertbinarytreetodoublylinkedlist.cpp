
//https://www.codingninjas.com/studio/problems/convert-a-given-binary-tree-to-doubly-linked-list_8230744?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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
    };

*************************************************************/

void help(BinaryTreeNode<int>* root, BinaryTreeNode<int>*& prev, BinaryTreeNode<int>*& head) {
    if (root == NULL) return;
    help(root->left, prev, head);
    if (head == NULL) head = root;
    root->left = prev;
    if (prev != NULL) prev->right = root;
    prev = root;
    help(root->right, prev, head);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* prev = NULL;
    BinaryTreeNode<int>* head = NULL;
    help(root, prev, head);
    return head;
}
