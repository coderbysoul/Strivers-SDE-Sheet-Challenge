//https://www.codingninjas.com/studio/problems/level-order-traversal_8230716?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root) {
    vector<int> result;

    if (root == nullptr)
        return result;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<int>* current = q.front();
        q.pop();

        result.push_back(current->val);

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }

    return result;
}
