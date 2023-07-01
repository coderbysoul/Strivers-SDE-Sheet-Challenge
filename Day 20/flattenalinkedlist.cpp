//https://www.codingninjas.com/studio/problems/flatten-a-linked-list_8230827?challengeSlug=striver-sde-challenge&leftPanelTab=1

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
#include <queue>

using namespace std;

class NodevaluePair {
public: 

int value;
Node *node;

NodevaluePair(Node* node,int value){
    this->node=node;
    this->value=value;
}

bool operator<(const NodevaluePair &other) const { return value > other.value; }
};



Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    Node* pointer=head;
    Node* result=NULL;

    //Heap to store all Nodevaluepairs

    priority_queue<NodevaluePair>pq;
    
    //Push the head nodes

    while (pointer != NULL) {
        pq.push(NodevaluePair(pointer, pointer->data));
        pointer=pointer->next;
    }

    //Add child nodes while popping out the minimum
    while(!pq.empty())
    {
        Node *temp=pq.top().node;
        pq.pop();

        //If the child of temp is not null add it to the temp
        if(temp->child!=NULL)
        pq.push(NodevaluePair(temp->child,temp->child->data));

        if (result == NULL) {
          result = temp;
          pointer=temp;
          pointer->next=NULL;
        } else {
            pointer->child=temp;
            pointer=temp;
            pointer->next=NULL;
        }
    }
    return result;

    
}
