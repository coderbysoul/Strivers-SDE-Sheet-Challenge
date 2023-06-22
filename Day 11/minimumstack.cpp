//https://www.codingninjas.com/studio/problems/min-stack_8230861?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

class minStack {
private:
    int capacity;
    int topIndex;
    vector<int> stack;
    vector<int> minimumStack;

public:
    // Constructor
    minStack() {
        capacity = 100000;
        topIndex = -1;
        stack.resize(capacity);
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num) {
        if (isFull())
            return;

        topIndex++;
        stack[topIndex] = num;

        if (topIndex == 0 || num <= minimumStack.back()) {
            minimumStack.push_back(num);
        }
    }

    // Function to remove the top element of the stack.
    int pop() {
        if (isEmpty())
            return -1;

        int poppedElement = stack[topIndex];
        topIndex--;

        if (poppedElement == minimumStack.back()) {
            minimumStack.pop_back();
        }

        return poppedElement;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top() {
        if (isEmpty())
            return -1;

        return stack[topIndex];
    }

    // Function to return the minimum element of stack if it is present. Otherwise return -1.
    int getMin() {
        if (isEmpty())
            return -1;

        return minimumStack.back();
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        int n = stack.size();
        return topIndex == n - 1;
    }
};
