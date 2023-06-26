//https://www.codingninjas.com/studio/problems/trapping-rain-water_8230693?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n) {
    if (n <= 2)
        return 0;

    long trappedWater = 0;
    int left = 0;
    int right = n - 1;
    long leftMax = 0;
    long rightMax = 0;

    while (left < right) {
        if (arr[left] < arr[right]) {
            if (arr[left] > leftMax) {
                leftMax = arr[left];
            } else {
                trappedWater += leftMax - arr[left];
            }
            left++;
        } else {
            if (arr[right] > rightMax) {
                rightMax = arr[right];
            } else {
                trappedWater += rightMax - arr[right];
            }
            right--;
        }
    }

    return trappedWater;
}
