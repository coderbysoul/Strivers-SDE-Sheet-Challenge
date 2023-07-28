//https://www.codingninjas.com/studio/problems/partial-bst_8230723?challengeSlug=striver-sde-challenge&leftPanelTab=1

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
bool isValid(BinaryTreeNode<int>*root,int minVal, int maxVal)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>maxVal || root->data<minVal){
        return false;
    }
    return (isValid(root->left, minVal, root->data)&& isValid(root->right, root->data, maxVal));
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isValid(root,INT_MIN, INT_MAX);
    
}