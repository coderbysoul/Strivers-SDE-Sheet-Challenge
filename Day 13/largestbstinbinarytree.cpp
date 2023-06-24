//https://www.codingninjas.com/studio/problems/size-of-largest-bst-in-binary-tree_8230743?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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

struct BSTInfo {
    bool isBST;
    int minVal;
    int maxVal;
    int size;

    BSTInfo(bool isBST, int minVal, int maxVal, int size)
        : isBST(isBST), minVal(minVal), maxVal(maxVal), size(size) {}
};

BSTInfo largestBSTHelper(TreeNode<int>* root) {
    if (root == nullptr) {
        // Base case: empty tree
        return BSTInfo(true, INT_MAX, INT_MIN, 0);
    }

    BSTInfo leftInfo = largestBSTHelper(root->left);
    BSTInfo rightInfo = largestBSTHelper(root->right);

    // Check if the current subtree is a valid BST
    bool isBST = (root->data > leftInfo.maxVal && root->data < rightInfo.minVal &&
                  leftInfo.isBST && rightInfo.isBST);

    // Calculate the size of the current subtree
    int size = isBST ? (1 + leftInfo.size + rightInfo.size) : std::max(leftInfo.size, rightInfo.size);

    // Determine the min and max values in the current subtree
    int minVal = isBST ? std::min(root->data, leftInfo.minVal) : INT_MIN;
    int maxVal = isBST ? std::max(root->data, rightInfo.maxVal) : INT_MAX;

    return BSTInfo(isBST, minVal, maxVal, size);
}

int largestBST(TreeNode<int>* root) {
    BSTInfo result = largestBSTHelper(root);
    return result.size;
}

