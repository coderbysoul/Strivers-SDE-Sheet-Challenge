//https://www.codingninjas.com/studio/problems/count-distinct-element-in-every-k-size-window_8230749?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int>& arr, int k) {
    vector<int> distinctCounts;

    unordered_map<int, int> frequencyMap;
    int distinctCount = 0;

    // Count the distinct elements in the first window of size k
    for (int i = 0; i < k; i++) {
        if (frequencyMap[arr[i]] == 0) {
            distinctCount++;
        }
        frequencyMap[arr[i]]++;
    }

    distinctCounts.push_back(distinctCount);

    // Process the remaining windows
    for (int i = k; i < arr.size(); i++) {
        // Remove the element going out of the window
        frequencyMap[arr[i - k]]--;
        if (frequencyMap[arr[i - k]] == 0) {
            distinctCount--;
        }

        // Add the new element entering the window
        if (frequencyMap[arr[i]] == 0) {
            distinctCount++;
        }
        frequencyMap[arr[i]]++;

        distinctCounts.push_back(distinctCount);
    }

    return distinctCounts;
}
