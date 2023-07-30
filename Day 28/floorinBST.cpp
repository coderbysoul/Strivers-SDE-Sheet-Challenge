//https://www.codingninjas.com/studio/problems/floor-in-bst_8230753?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int>*root, int X,int &val)
{
    if(root==NULL)
    return;

    if(root->val==X)
    {
        val=root->val;
        return;
    }
    else if(root->val<X)
    {
        val=root->val;
        solve(root->right,X,val);
    }
    else
    {
        solve(root->left,X,val);
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int val=INT_MAX;
    solve(root,X,val);
    if(val==INT_MAX)
    return -1;
    return val;
}