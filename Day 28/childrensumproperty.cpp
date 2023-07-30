//https://www.codingninjas.com/studio/problems/children-sum-property_8230711?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode<int>* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    // Recursively fix left and right subtrees
    changeTree(root->left);
    changeTree(root->right);

    int l = (root->left) ? root->left->data : 0;
    int r = (root->right) ? root->right->data : 0;

    if (root->data <= l + r) {
        root->data = l + r;
    } else {
        if (root->left) {
            root->left->data = root->data - r;
            changeTree(root->left);
        } else {
            root->right->data = root->data - l;
            changeTree(root->right);
        }
    }
}
