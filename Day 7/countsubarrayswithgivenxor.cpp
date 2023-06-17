//https://www.codingninjas.com/codestudio/problems/count-subarrays-with-given-xor_8230830?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x) {
    unordered_map<int, int> xorPrefixSumFreq;
    int xorSum = 0;
    int count = 0;

    
    for (int num : arr) {
        
        xorSum ^= num;

        
        if (xorSum == x)
            count++;

        
        if (xorPrefixSumFreq.find(xorSum ^ x) != xorPrefixSumFreq.end())
            count += xorPrefixSumFreq[xorSum ^ x];

        
        xorPrefixSumFreq[xorSum]++;
    }

    return count;
}
