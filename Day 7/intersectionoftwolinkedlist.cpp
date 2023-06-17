//https://www.codingninjas.com/codestudio/problems/intersection-of-two-linked-lists_8230688?challengeSlug=striver-sde-challenge&leftPanelTab=1

Node* findIntersection(Node* firstHead, Node* secondHead) {
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;

    
    while (temp1 != temp2) {
        // If either list reaches the end, move to the head of the other list
        temp1 = (temp1 == nullptr) ? secondHead : temp1->next;
        temp2 = (temp2 == nullptr) ? firstHead : temp2->next;
    }

    
    return temp1;
}
