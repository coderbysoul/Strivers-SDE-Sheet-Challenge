//https://www.codingninjas.com/studio/problems/binary-tree-zigzag-traversal_8230796?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int>* root) {
    vector<int> result;

    if (root == NULL) {
        return result;
    }

    queue<BinaryTreeNode<int>*> q;
    stack<int> s;
    bool leftToRight = true;

    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < size; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();

            if (leftToRight) {
                currentLevel.push_back(node->data);
            } else {
                s.push(node->data);
            }

            if (node->left != NULL) {
                q.push(node->left);
            }

            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        if (!leftToRight) {
            while (!s.empty()) {
                currentLevel.push_back(s.top());
                s.pop();
            }
        }

        leftToRight = !leftToRight;
        result.insert(result.end(), currentLevel.begin(), currentLevel.end());
    }

    return result;
}




