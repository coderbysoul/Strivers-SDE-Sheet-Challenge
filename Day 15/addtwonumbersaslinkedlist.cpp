//https://www.codingninjas.com/studio/problems/add-two-numbers-as-linked-lists_8230833?challengeSlug=striver-sde-challenge&leftPanelTab=1

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node* addTwoNumbers(Node* num1, Node* num2) {
    Node* dummy = new Node(); // Dummy node to hold the result
    Node* curr = dummy; // Pointer to the current node in the result list
    int carry = 0;

    while (num1 != nullptr || num2 != nullptr || carry != 0) {
        int sum = carry;

        if (num1 != nullptr) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2 != nullptr) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        curr->next = new Node(digit);
        curr = curr->next;
    }

    return dummy->next;
}
