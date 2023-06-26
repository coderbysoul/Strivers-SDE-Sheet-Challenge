//https://www.codingninjas.com/studio/problems/linked-list-cycle-ii_8230823?challengeSlug=striver-sde-challenge&leftPanelTab=1

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

Node *firstNode(Node *head) {
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *slow = head;
    Node *fast = head;

    // Detect the cycle using Floyd's Tortoise and Hare algorithm
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // No cycle found
    if (fast == nullptr || fast->next == nullptr)
        return nullptr;

    // Move slow pointer back to head
    slow = head;

    // Move slow and fast pointers at the same speed until they meet at the first node of the cycle
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
