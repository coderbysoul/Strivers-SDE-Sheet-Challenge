//https://www.codingninjas.com/studio/problems/is-height-balanced-binary-tree_8230771?challengeSlug=striver-sde-challenge&leftPanelTab=1

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

int height(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return std::max(leftHeight, rightHeight) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int heightDiff = std::abs(leftHeight - rightHeight);

    if (heightDiff > 1)
        return false;

    bool isLeftBalanced = isBalancedBT(root->left);
    bool isRightBalanced = isBalancedBT(root->right);

    return isLeftBalanced && isRightBalanced;
}


