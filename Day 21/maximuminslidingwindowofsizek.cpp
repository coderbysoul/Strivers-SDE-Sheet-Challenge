//https://www.codingninjas.com/studio/problems/maximum-in-sliding-windows-of-size-k_8230772?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int k) {
    vector<int> result;
    deque<int> dq;

    // Process the first k elements separately
    for (int i = 0; i < k; i++) {
        // Remove elements from the deque that are smaller than the current element
        while (!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();
        
        dq.push_back(i); // Store the index in the deque
    }

    // Process the remaining elements
    for (int i = k; i < nums.size(); i++) {
        result.push_back(nums[dq.front()]); // The front of the deque contains the maximum for the previous window
        
        // Remove elements from the deque that are outside the current window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        
        // Remove elements from the deque that are smaller than the current element
        while (!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();
        
        dq.push_back(i); // Store the index in the deque
    }

    result.push_back(nums[dq.front()]); // Add the maximum for the last window

    return result;
}