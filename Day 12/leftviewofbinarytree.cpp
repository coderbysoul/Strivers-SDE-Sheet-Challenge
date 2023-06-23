//https://www.codingninjas.com/studio/problems/left-view-of-a-binary-tree_8230757?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void helper(TreeNode<int>*root,vector<int>&res,int level)
{
    if(root==NULL)
     return;

    if(level==res.size()) 
     res.push_back(root->data);

    helper(root->left,res,level+1) ;
    helper(root->right,res,level+1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int>res;
    helper(root,res,0);
    return res;
    
}