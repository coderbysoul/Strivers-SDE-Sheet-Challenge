//https://www.codingninjas.com/studio/problems/day-29-k-max-sum-combinations_8230768?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    priority_queue<int>pq;
    vector<int>ans(k);

    for(int i=0;i<n;i++)
    
        for(int j=0;j<n;j++)
        pq.push(a[i]+b[j]);
        
        for(int i=0;i<k;i++)
        {
            ans[i]=pq.top();
            pq.pop();
        }
        return ans;
    
}