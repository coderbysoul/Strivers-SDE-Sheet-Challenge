//https://www.codingninjas.com/studio/problems/0-1-knapsack_8230801?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<int>prev(w+1,0);

	for(int i=weights[0];i<=w;i++)
	{
		prev[i]=values[0];
	}
	for(int i=1;i<n;i++)
	{
		for(int W=w;W>=0;W--)
		{
			int notPick=prev[W];
			int pick=INT_MIN;
			if(weights[i]<=W)
			pick=values[i]+prev[W-weights[i]];
			prev[W]=max(pick,notPick);
		}
	}
	return prev[w];
}