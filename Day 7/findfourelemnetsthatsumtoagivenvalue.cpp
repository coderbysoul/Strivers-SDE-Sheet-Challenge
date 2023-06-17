//https://www.codingninjas.com/codestudio/problems/find-four-elements-that-sums-to-a-given-value_8230785?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end()); // Sort the array in ascending order
    int size = arr.size();

    for (int i = 0; i < size - 3; i++) {
        for (int j = i + 1; j < size - 2; j++) {
            int left = j + 1; // Left pointer
            int right = size - 1; // Right pointer

            while (left < right) {
                int sum = arr[i] + arr[j] + arr[left] + arr[right];

                if (sum == target) {
                    // Found a quadruplet that sums to the target
                    return "Yes";
                } else if (sum < target) {
                    // Sum is smaller than target, move the left pointer to increase the sum
                    left++;
                } else {
                    // Sum is larger than target, move the right pointer to decrease the sum
                    right--;
                }
            }
        }
    }

    // No quadruplet found
    return "No";
}
