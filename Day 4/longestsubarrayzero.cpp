//https://www.codingninjas.com/codestudio/problems/longest-subarray-zero-sum_8230747?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int sum=0;
  int maxLen=0;
  unordered_map<int,int>mp;
  for(int i=0;i<arr.size();i++)
  {
    sum+=arr[i];
    if(sum==0)
    {
     maxLen=i+1;
    }
    else if(mp.find(sum)!=mp.end())
    {
      maxLen=max(maxLen,i-mp[sum]);
    }
    else
    {
      mp[sum]=i;
    }
  }
  return maxLen;

}