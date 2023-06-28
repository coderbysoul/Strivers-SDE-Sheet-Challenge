//https://www.codingninjas.com/studio/problems/kth-largest-element-in-the-unsorted-array_8230740?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int i = 0; i < K; i++) {
        minHeap.push(arr[i]);
    }
    
    for (int i = K; i < size; i++) {
        if (arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    
    return minHeap.top();
}