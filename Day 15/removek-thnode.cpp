//https://www.codingninjas.com/studio/problems/delete-kth-node-from-end_8230725?challengeSlug=striver-sde-challenge&leftPanelTab=1

/*
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
*/

Node* removeKthNode(Node* head, int K)
{
    if (head == NULL || K <= 0)
        return head;

    // Initialize two pointers, first and second
    Node* first = head;
    Node* second = head;

    // Move the second pointer K nodes ahead of the first pointer
    for (int i = 0; i < K; i++)
    {
        if (second == NULL)
            return head; // K is greater than the length of the list
        second = second->next;
    }

    // If second pointer becomes NULL, it means K is equal to the length of the list
    // In this case, remove the first node (head) and update the head pointer
    if (second == NULL)
    {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    // Move both pointers simultaneously until the second pointer reaches the end of the list
    while (second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }

    // Remove the Kth node by updating the next pointer of the (K-1)th node
    Node* temp = first->next;
    first->next = temp->next;
    delete temp;

    return head;
}

