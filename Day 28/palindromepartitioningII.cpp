//https://www.codingninjas.com/studio/problems/palindrome-partitioning-ll_8230732?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
bool isPalin(int i,int j,string s)
{
  while (i < j) {
    if (s[i] != s[j])
      return false;
    i++;
    j--;
  }
  return true;
}

int helper(int i,int n,string s,vector<int>&dp)
{
    if(i==n)
    return 0;

    int mincut=INT_MAX;

    if(dp[i]!=0)
    return dp[i];

    for(int j=i;j<n;j++)
    {
        if(isPalin(i,j,s)){
            int cut=1+helper(j+1,n,s,dp);
            mincut=min(mincut,cut);
        }
    }
    return dp[i]=mincut;
}
int palindromePartitioning(string str)
{
    // Write your code here
    int n=str.size();
    vector<int>dp(n,0);
    return helper(0,n,str,dp)-1;
}
