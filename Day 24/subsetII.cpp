//https://www.codingninjas.com/studio/problems/subsets-ii_8230855?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 

void solve(int ind, vector<int>&arr, vector<int>&temp, vector<vector<int>>&ans)
{
    ans.push_back(temp);
    for(int i=ind;i<arr.size();i++)
    {
        if(i!=ind && arr[i]==arr[i-1])
        continue;
        temp.push_back(arr[i]);
        solve(i+1,arr,temp,ans);
        temp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>temp;
    sort(arr.begin(),arr.end());
    solve(0,arr,temp,ans);
    return ans;
}