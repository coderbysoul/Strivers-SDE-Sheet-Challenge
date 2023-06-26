//https://www.codingninjas.com/studio/problems/lca-of-binary-tree_8230760?challengeSlug=striver-sde-challenge&leftPanelTab=1

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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y) {
    if (root == NULL) {
        return -1;  // Return -1 if the root is NULL (not found)
    }
    
    if (root->data == x || root->data == y) {
        return root->data;  // Return the root's data if it matches either of the values
    }
    
    int leftLCA = lowestCommonAncestor(root->left, x, y);
    int rightLCA = lowestCommonAncestor(root->right, x, y);
    
    if (leftLCA != -1 && rightLCA != -1) {
        return root->data;  // If both values are found in different subtrees, return the root's data
    }
    
    return (leftLCA != -1) ? leftLCA : rightLCA;  // Return the non-negative LCA (either from the left or right subtree)
}
