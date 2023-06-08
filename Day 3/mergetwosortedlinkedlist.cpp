//https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_8230729?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

template <typename T>
Node<T>* sortTwoLists(Node<T>* first, Node<T>* second) {
    if (first == nullptr) {
        return second;
    }
    if (second == nullptr) {
        return first;
    }

    Node<T>* mergedList = nullptr;
    if (first->data <= second->data) {
        mergedList = first;
        first = first->next;
    } else {
        mergedList = second;
        second = second->next;
    }

    Node<T>* curr = mergedList;

    while (first != nullptr && second != nullptr) {
        if (first->data <= second->data) {
            curr->next = first;
            first = first->next;
        } else {
            curr->next = second;
            second = second->next;
        }
        curr = curr->next;
    }

    if (first != nullptr) {
        curr->next = first;
    } else {
        curr->next = second;
    }

    return mergedList;
}

