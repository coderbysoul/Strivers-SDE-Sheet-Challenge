//https://www.codingninjas.com/studio/problems/ceil-from-bst_8230754?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ceil=-1;
    while(node)
    {
        if(x==node->data)
        {
            ceil=node->data;
            return ceil;
        }

        else if(x>node->data)
        {
            node=node->right;
        }
        else{
            ceil=node->data;
            node=node->left;
            
        }
       
    }
     return ceil;
}