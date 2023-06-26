//https://www.codingninjas.com/studio/problems/cycle-detection-in-a-singly-linked-list_8230683?challengeSlug=striver-sde-challenge&leftPanelTab=1

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

bool detectCycle(Node *head)
{
	//	Write your code here
    if(head==NULL || head->next==NULL)
     return false;

    Node *slow=head;
    Node *fast=head; 

    while(fast!=NULL && fast->next!=NULL) 
    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
         return true;
    }
    

    return false; 
}