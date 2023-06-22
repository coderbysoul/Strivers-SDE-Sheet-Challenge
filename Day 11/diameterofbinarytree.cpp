//https://www.codingninjas.com/studio/problems/diameter-of-binary-tree_8230762?challengeSlug=striver-sde-challenge

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int height(TreeNode<int> *root) {
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode<int> *root) {
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int ldiameter = diameterOfBinaryTree(root->left);
    int rdiameter = diameterOfBinaryTree(root->right);

    return max(lh + rh, max(ldiameter, rdiameter));
}

