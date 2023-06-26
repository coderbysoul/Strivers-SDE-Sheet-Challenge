//https://www.codingninjas.com/studio/problems/3sum_8230739?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    vector<vector<int>> result;
    if (n < 3)
        return result;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicates for the first element
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == K) {
                result.push_back({arr[i], arr[left], arr[right]});
                // Skip duplicates for the second element
                while (left < right && arr[left] == arr[left + 1])
                    left++;
                // Skip duplicates for the third element
                while (left < right && arr[right] == arr[right - 1])
                    right--;
                left++;
                right--;
            } else if (sum < K) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}
