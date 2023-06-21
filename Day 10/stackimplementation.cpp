//https://www.codingninjas.com/studio/problems/stack-implementation-using-array_8230854?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
// Stack class.


class Stack {
private:
    int capacity;        // Maximum capacity of the stack
    int topIndex;        // Index of the top element in the stack
    vector<int> data;  // Array to store the stack elements

public:
    Stack(int capacity) {
        this->capacity = capacity;
        this->topIndex = -1;
        this->data.resize(capacity);
    }

    void push(int num) {
        if (isFull()) {
            
            return;
        }

        topIndex++;
        data[topIndex] = num;
    }

    int pop() {
        if (isEmpty()) {
            
            return -1;  // Return some default value indicating stack underflow
        }

        int poppedElement = data[topIndex];
        topIndex--;

        return poppedElement;
    }
    
    int top() {
        if (isEmpty()) {
            
            return -1;  // Return some default value indicating stack is empty
        }

        return data[topIndex];
    }
    
    bool isEmpty() {
        return topIndex == -1;
    }
    
    bool isFull() {
        return topIndex == capacity - 1;
    }
};
