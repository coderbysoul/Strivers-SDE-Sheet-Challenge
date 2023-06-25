//https://www.codingninjas.com/studio/problems/bottom-view-of-binary-tree_8230745?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> *root) {
    // Define a map to store the horizontal distance and corresponding node value
    map<int, int> nodeMap;
    
    // Create a queue to perform level order traversal
    queue<pair<BinaryTreeNode<int>*, int>> q;
    
    // Enqueue the root node with horizontal distance 0
    q.push({root, 0});
    
    while (!q.empty()) {
        BinaryTreeNode<int>* node = q.front().first;
        int horizontalDist = q.front().second;
        q.pop();
        
        // Update the node value in the map for the corresponding horizontal distance
        nodeMap[horizontalDist] = node->data;
        
        // Enqueue the left child with horizontal distance decreased by 1
        if (node->left)
            q.push({node->left, horizontalDist - 1});
        
        // Enqueue the right child with horizontal distance increased by 1
        if (node->right)
            q.push({node->right, horizontalDist + 1});
    }
    
    // Extract the node values from the map and store them in a vector
    vector<int> result;
    for (auto it : nodeMap)
        result.push_back(it.second);
    
    return result;
}
