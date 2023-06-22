//https://www.codingninjas.com/studio/problems/implement-a-queue_8230848?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 

class Queue {
private:
    int frontIndex;      // Position of the front element
    int rearIndex;       // Position of the last element
    int size;       // Number of elements present in the queue
    int queueSize;  // Total size of the queue
    int* q;         // Array to store the queue elements

public:
    Queue() {
        queueSize = 5000;   // Assuming a maximum queue size of 1000
        q = new int[queueSize];
        frontIndex =  size = 0;
        rearIndex =-1;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == queueSize;
    }

    void enqueue(int data) {
        if (isFull()) {
            return;
        }
        rearIndex++;
        q[rearIndex] = data;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int ans = q[frontIndex];
        frontIndex ++;
        size--;
        if (size == 0) {
        frontIndex = 0;
        rearIndex = -1;
    }
        return ans;
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }
        return q[frontIndex];
    }
};
