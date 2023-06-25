//https://www.codingninjas.com/studio/problems/maximum-width-in-binary-tree_8230710?challengeSlug=striver-sde-challenge&leftPanelTab=1

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

int getMaxWidth(TreeNode<int> *root) {
    if (root == nullptr)
        return 0;

    int maxWidth = 0;

    // Create a queue for level order traversal
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at the current level

        // Update the maximum width if necessary
        maxWidth = max(maxWidth, levelSize);

        // Process all nodes at the current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode<int>* node = q.front();
            q.pop();

            // Enqueue the left child
            if (node->left)
                q.push(node->left);

            // Enqueue the right child
            if (node->right)
                q.push(node->right);
        }
    }

    return maxWidth;
}
