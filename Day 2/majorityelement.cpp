//https://www.codingninjas.com/codestudio/problems/day-6-majority-element_8230731?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
	mp[arr[i]]++;

	for(auto x:mp)
	{
		if(x.second>n/2)
		return x.first;
	}
	return -1;
}