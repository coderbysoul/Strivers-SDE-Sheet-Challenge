//https://www.codingninjas.com/codestudio/problems/copy-list-with-random-pointer_8230734?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if (head == nullptr)
        return nullptr;

    LinkedListNode<int> *curr = head;
    while (curr != nullptr)
    {
        LinkedListNode<int> *temp = curr->next;
        curr->next = new LinkedListNode<int>(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    curr = head;

    while (curr != nullptr)
    {
        if (curr->next != nullptr)
        {
            curr->next->random = (curr->random != nullptr) ? curr->random->next : nullptr;
        }
        curr = curr->next ? curr->next->next : nullptr;
    }

    LinkedListNode<int> *org = head;
    LinkedListNode<int> *copy = head->next;
    LinkedListNode<int> *temp = copy;
    while (org != nullptr)
    {
        org->next = org->next ? org->next->next : nullptr;
        copy->next = copy->next ? copy->next->next : nullptr;
        org = org->next;
        copy = copy->next;
    }
    return temp;
}




