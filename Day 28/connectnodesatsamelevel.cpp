//https://www.codingninjas.com/studio/problems/connect-nodes-at-same-level_8230790?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode<int>* root) {
    if (root == nullptr)
        return;

    std::queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        BinaryTreeNode<int>* prev = nullptr;

        for (int i = 0; i < size; i++) {
            BinaryTreeNode<int>* current = q.front();
            q.pop();

            // Connect the nodes at the same level
            if (prev != nullptr)
                prev->next = current;

            prev = current;

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }
    }
}