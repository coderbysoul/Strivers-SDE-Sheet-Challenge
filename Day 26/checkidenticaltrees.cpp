//https://www.codingninjas.com/studio/problems/check-identical-trees_8230719?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    bool left = identicalTrees(root1->left, root2->left);   // Corrected recursive call
    bool right = identicalTrees(root1->right, root2->right); // Corrected recursive call
    bool val = root1->data == root2->data;

    if (left && right && val) {
        return true;
    } else {
        return false;
    }
}
