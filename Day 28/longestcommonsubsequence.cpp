//https://www.codingninjas.com/studio/problems/longest-common-subsequence_8230681?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
int lcs(string s, string t)
{
	//Write your code here
	int n1=s.size();
	int n2=t.size();
	vector<int>curr(n2+1,0);
	vector<int>next(n2+1,0);
	for(int i=n1-1;i>=0;i--)
	{
		for(int j=n2-1;j>=0;j--)
		{
			int ans=0;
			if(s[i]==t[j])
			{
				ans=1+next[j+1];
			}

			else
			{
				ans=max(next[j],curr[j+1]);
			}
			curr[j]=ans;
		}
		next=curr;
	}
return next[0];
}