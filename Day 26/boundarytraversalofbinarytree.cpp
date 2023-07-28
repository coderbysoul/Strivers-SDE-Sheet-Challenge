//https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_8230712?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void leftTraversal(TreeNode<int>* root, vector<int>& ans) {
    // Base case
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        return;
    }
    ans.push_back(root->data);
    if (root->left) {
        leftTraversal(root->left, ans);
    } else {
        leftTraversal(root->right, ans);
    }
}

void leafTraversal(TreeNode<int>* root, vector<int>& ans) {
    // Base case
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}

void rightTraversal(TreeNode<int>* root, vector<int>& ans) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        return;
    }
    if (root->right) {
        rightTraversal(root->right, ans);
    } else {
        rightTraversal(root->left, ans);
    }
    // Add data while returning
    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    ans.push_back(root->data);

    // Left Traversal
    leftTraversal(root->left, ans);

    // Traverse leaf nodes in the left subtree
    leafTraversal(root->left, ans);

    // Traverse leaf nodes in the right subtree
    leafTraversal(root->right, ans);

    // Traverse right part
    rightTraversal(root->right, ans);

    return ans;
}
