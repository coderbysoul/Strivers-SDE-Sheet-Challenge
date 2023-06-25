//https://www.codingninjas.com/studio/problems/top-view-of-binary-tree_8230721?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> result;

    if (root == nullptr) {
        return result; // Return an empty result if the tree is empty
    }

    // Define a map to store the horizontal distance and corresponding node value
    map<int, int> nodeMap;

    // Create a queue to perform level order traversal
    queue<pair<TreeNode<int>*, int>> q;

    // Enqueue the root node with horizontal distance 0
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode<int>* node = q.front().first;
        int horizontalDist = q.front().second;
        q.pop();

        // If the horizontal distance is not present in the map, add the node value to the map
        if (nodeMap.find(horizontalDist) == nodeMap.end()) {
            nodeMap[horizontalDist] = node->val;
        }

        // Enqueue the left child with horizontal distance decreased by 1
        if (node->left)
            q.push({node->left, horizontalDist - 1});

        // Enqueue the right child with horizontal distance increased by 1
        if (node->right)
            q.push({node->right, horizontalDist + 1});
    }

    // Extract the node values from the map and store them in a vector
    for (auto it : nodeMap)
        result.push_back(it.second);

    return result;
}
