//https://www.codingninjas.com/studio/problems/construct-binary-tree-from-inorder-and-postorder-traversal_8230837?challengeSlug=striver-sde-challenge&leftPanelTab=1

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/

int findIndex(vector<int> &inOrder,int element)
{   
    for(int i=0;i<inOrder.size();i++)
    {        
        if(inOrder[i]==element)            
        return i;    
    }    
    return -1; 
} 
 
TreeNode<int> * solve(vector<int> &postOrder, vector<int> &inOrder,int &index,int inorderStart,int inorderEnd,int size)
{    
    if( index >=size || inorderStart>inorderEnd ) 
    {
        return NULL;
    }  
 
    int element=postOrder[index--];    
 
    TreeNode<int> *root=new TreeNode<int>(element);    
 
    int position=findIndex(inOrder,element);    
 
    root->right=solve(postOrder,inOrder,index,position+1,inorderEnd,size);
    root->left=solve(postOrder,inOrder,index,inorderStart,position-1,size);     
       
    return root; 
}
 
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
    // Write your code here.   
    int n=inOrder.size(); 
    int index=n-1;   
    TreeNode<int> *root=solve(postOrder,inOrder,index,0,n-1,n);    
    return root;
}
