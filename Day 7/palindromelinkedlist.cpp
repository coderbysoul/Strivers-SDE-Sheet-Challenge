//https://www.codingninjas.com/codestudio/problems/palindrome-linked-list_8230717?challengeSlug=striver-sde-challenge&leftPanelTab=1

template <typename T>
bool isPalindrome(LinkedListNode<T> *head) {
    
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    
    LinkedListNode<T> *slow = head;
    LinkedListNode<T> *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

   
    LinkedListNode<T> *prev = nullptr;
    LinkedListNode<T> *curr = slow;
    LinkedListNode<T> *next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    
    LinkedListNode<T> *firstHalf = head;
    LinkedListNode<T> *secondHalf = prev;
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}


