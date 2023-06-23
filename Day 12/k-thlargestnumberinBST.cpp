//https://www.codingninjas.com/studio/problems/k-th-largest-number-bst_8230750?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

int KthLargestNumber(TreeNode<int>* root, int k) {
    stack<TreeNode<int>*> st;
    TreeNode<int>* curr = root;
    int count = 0;
    int kthLargest = -1;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->right;
        }

        curr = st.top();
        st.pop();
        count++;

        if (count == k) {
            kthLargest = curr->data;
            break;
        }

        curr = curr->left;
    }

    return kthLargest;
}
