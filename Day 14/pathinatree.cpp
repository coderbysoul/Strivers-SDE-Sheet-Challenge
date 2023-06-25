//https://www.codingninjas.com/studio/problems/path-in-a-tree_8230860?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/


bool pathInATreeHelper(TreeNode<int> *node, int x, vector<int> &path) {
    if (node == nullptr)
        return false;

    // Add the current node to the path
    path.push_back(node->data);

    // Check if the current node is the target node x
    if (node->data == x)
        return true;

    // Recursively search in the left and right subtrees
    bool foundInLeft = pathInATreeHelper(node->left, x, path);
    bool foundInRight = pathInATreeHelper(node->right, x, path);

    // If the target node was not found in the current subtree, remove the current node from the path
    if (!foundInLeft && !foundInRight)
        path.pop_back();

    return foundInLeft || foundInRight;
}

vector<int> pathInATree(TreeNode<int> *root, int x) {
    vector<int> path;
    pathInATreeHelper(root, x, path);
    return path;
}
