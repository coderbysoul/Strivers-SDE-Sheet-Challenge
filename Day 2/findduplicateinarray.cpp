//https://www.codingninjas.com/codestudio/problems/find-duplicate-in-array_8230816?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	unordered_map<int,int>mp;
	for(int x:arr)
	 mp[x]++;

	for(auto x:mp)
	{
		if(x.second>1)
		return x.first;
	} 
	return -1;
}
