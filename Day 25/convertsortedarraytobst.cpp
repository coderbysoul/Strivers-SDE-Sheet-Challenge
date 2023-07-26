//https://www.codingninjas.com/studio/problems/convert-sorted-array-to-bst_8230836?challengeSlug=striver-sde-challenge

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

TreeNode<int>* help(vector<int> &arr,int s,int e){ 
     if(s>e)
      return NULL;
     int m=(s+e)/2;
     TreeNode<int>* root=new TreeNode<int>(arr[m]);
        root->left=help(arr,s,m-1);
        root->right=help(arr,m+1,e); 
       return root; 
    } 
    TreeNode<int>* sortedArrToBST(vector<int> &arr, int n) { 
        // Write your code here.
         return help(arr,0,n-1);
     }