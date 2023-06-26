//https://www.codingninjas.com/studio/problems/rotate-linked-list_8230752?challengeSlug=striver-sde-challenge&leftPanelTab=1

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
    if (head == nullptr || k == 0) {
        return head;
    }

    int length = 0;
    Node *current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }

    int rotation = k % length;
    if (rotation == 0) {
        return head;
    }

    int count = length - rotation;
    current = head;
    Node *newHead = nullptr;

    while (count > 1) {
        current = current->next;
        count--;
    }

    newHead = current->next;
    current->next = nullptr;

    current = newHead;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = head;

    return newHead;
}
