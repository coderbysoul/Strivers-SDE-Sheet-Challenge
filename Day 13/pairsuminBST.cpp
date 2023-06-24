//https://www.codingninjas.com/studio/problems/pair-sum-in-bst_8230756?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

bool pairSumBst(BinaryTreeNode<int> *root, int k) {
    unordered_set<int> complementSet;

    // In-order traversal using stack
    stack<BinaryTreeNode<int>*> nodes;
    BinaryTreeNode<int>* curr = root;

    while (curr != nullptr || !nodes.empty()) {
        while (curr != nullptr) {
            nodes.push(curr);
            curr = curr->left;
        }

        curr = nodes.top();
        nodes.pop();

        // Check if the complement exists in the set
        if (complementSet.count(curr->data) > 0) {
            return true;
        }

        // Add the current value to the set
        complementSet.insert(k - curr->data);

        curr = curr->right;
    }

    return false;
}