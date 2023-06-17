//https://www.codingninjas.com/codestudio/problems/longest-consecutive-sequence_8230708?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> numsSet;

    // Insert all elements of the array into the HashSet
    for (int num : arr) {
        numsSet.insert(num);
    }

    int longestSequence = 0;

    // Iterate over each element in the array
    for (int num : arr) {
        // Check if the current number is the start of a sequence
        if (numsSet.find(num - 1) == numsSet.end()) {
            int currentNum = num;
            int currentSequence = 1;

            // Check for consecutive elements in the sequence
            while (numsSet.find(currentNum + 1) != numsSet.end()) {
                currentNum++;
                currentSequence++;
            }

            // Update the longest sequence length
            longestSequence = max(longestSequence, currentSequence);
        }
    }

    return longestSequence;
}
