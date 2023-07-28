//https://www.codingninjas.com/studio/problems/kth-smallest-node-in-bst_8230751?challengeSlug=striver-sde-challenge&leftPanelTab=1

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

void help(TreeNode<int> *root, int &k,int &res) { 
    if(root==NULL) 
     return; 
    help(root->left,k,res);
    if(k!=0) { 
      k--;
      res=root->data; 
    } 
    help(root->right,k,res); 
   } 
          
 int kthSmallest(TreeNode<int> *root, int k) {
 // Write the code here. 
  int res=0;
  help(root,k,res);
  return res;
 }