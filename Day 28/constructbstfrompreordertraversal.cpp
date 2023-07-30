//https://www.codingninjas.com/studio/problems/construct-bst-from-preorder-traversal_8230850?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* help(vector<int>& preOrder, int s, int e) {
    if (s > e) return NULL;

    int rvalue = preOrder[s];
    int i = s + 1, j = e;

    while (i <= j) {
        int m = (i + j) / 2;
        if (preOrder[m] >= rvalue) {
            j = m - 1;
        } else {
            i = m + 1;
        }
    }

    TreeNode<int>* root = new TreeNode<int>(rvalue);
    root->left = help(preOrder, s + 1, j);
    root->right = help(preOrder, j + 1, e);

    return root;
}

TreeNode<int>* preOrderTree(vector<int>& preOrder) {
    return help(preOrder, 0, preOrder.size() - 1);
}