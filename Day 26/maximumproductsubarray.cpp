//https://www.codingninjas.com/studio/problems/maximum-product-subarray_8230828?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n) {
    int mx1 = INT_MIN, mx2 = INT_MIN, c1 = 0, c2 = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (c1 == 0) {
            c1 = arr[i];
        } else {
            c1 *= arr[i];
        }
        if (c2 == 0) {
            c2 = arr[n - 1 - i];
        } else {
            c2 *= arr[n - 1 - i];
        }
        mx1 = max(mx1, c1);
        mx2 = max(mx2, c2);
    }
    return max(mx1, mx2);
}
