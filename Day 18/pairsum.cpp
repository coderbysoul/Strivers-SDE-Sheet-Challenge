//https://www.codingninjas.com/studio/problems/pair-sum_8230699?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int>& arr, int s) {
    vector<vector<int>> res;
    map<int, int> freq;

    for (int i = 0; i < arr.size(); i++) {
        int complement = s - arr[i];
        
        if (freq.find(complement) != freq.end()) {
            int count = freq[complement];
            
            for (int j = 0; j < count; j++) {
              vector<int> pair{arr[i], complement};
              sort(pair.begin(),pair.end());
              res.push_back(pair);
            }
        }

        freq[arr[i]]++;
    }
     sort(res.begin(), res.end());
    return res;
}