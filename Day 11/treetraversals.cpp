//https://www.codingninjas.com/studio/problems/tree-traversals_8230775?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

void inorder(BinaryTreeNode<int> *root,vector<int>&ans)
{
   if(root==NULL)
    return;

    
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

void postorder(BinaryTreeNode<int> *root,vector<int>&ans)
{
    if(root==NULL)
     return;

    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->data); 
}

void preorder(BinaryTreeNode<int> *root,vector<int>&ans)
{
    if(root==NULL)
    return;

  ans.push_back(root->data);
  preorder(root->left,ans);
  preorder(root->right,ans);
  

}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
   vector<vector<int>>ans;

    vector<int>in_traversal;
    vector<int>pre_traversal;
    vector<int>post_traversal;

    inorder(root,in_traversal);
    ans.push_back(in_traversal);
    preorder(root,pre_traversal);
    ans.push_back(pre_traversal);
    postorder(root,post_traversal);
    ans.push_back(post_traversal);

    return ans;

    

}