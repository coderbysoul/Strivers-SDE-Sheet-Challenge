//https://www.codingninjas.com/studio/problems/longest-common-prefix_8230847?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    sort(arr.begin(),arr.end());
    string s1=arr[0];
    string s2=arr[n-1];
    string ans="";
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]==s2[i])
        {
            ans.push_back(s1[i]);
        }
        else
        {
            break;
        }
    }
    return ans;
}


