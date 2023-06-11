//https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_8230733?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	pair<int,int>ans;
	unordered_map<int,int>mp;

	for(int x:arr)
	mp[x]++;

	for(int i=1;i<=n;i++)
	{
		if(mp[i]==0)
		ans.first=i;
	}

	for(auto x:mp)
	{

          if (x.second > 1) {
            ans.second = x.first;
            
          }
        }

	return ans;
	
}
