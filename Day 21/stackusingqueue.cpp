//https://www.codingninjas.com/studio/problems/stack-using-queue_8230715?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    Stack() {}

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void push(int element) {
        q2.push(element);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        if (isEmpty()) {
            
            return -1 ;
        }

        int topElement = q1.front();
        q1.pop();

        return topElement;
    }

    int top() {
        if (isEmpty()) {
            
            return -1;
        }

        return q1.front();
    }
};

