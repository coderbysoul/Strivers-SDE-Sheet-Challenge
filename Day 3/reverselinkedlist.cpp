//https://www.codingninjas.com/codestudio/problems/reverse-linked-list_8230724?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

template <typename T>
LinkedListNode<T>* reverseLinkedList(LinkedListNode<T>* head) {
    LinkedListNode<T>* prev = nullptr;
    LinkedListNode<T>* curr = head;

    while (curr != nullptr) {
        LinkedListNode<T>* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}
