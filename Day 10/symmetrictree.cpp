//https://www.codingninjas.com/studio/problems/symmetric-tree_8230686?challengeSlug=striver-sde-challenge&leftPanelTab=1

/*****************************************************

    Following is the Binary Tree node structure:
    
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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool isMirror(BinaryTreeNode<int>*left, BinaryTreeNode<int>*right)
{
    if(left==NULL && right==NULL)
     return true;

    if(left==NULL || right==NULL || left->data!=right->data) 
    return false;

    return isMirror(left->left, right->right) && isMirror(left->right,right->left);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(root==NULL)
    return true;

    return isMirror(root->left,root->right);

}