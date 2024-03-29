//https://www.codingninjas.com/studio/problems/next-smaller-element_8230814?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>s;
    s.push(-1);

    vector<int>ans(n);

    for(int i=n-1;i>=0;i--)
    {
        int curr=arr[i];

        while(s.top()>=curr)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}