//https://www.codingninjas.com/studio/problems/online-stock-span_8230843?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    vector<int>ans;
    int n=price.size();
    vector<int>prev_greater(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&price[st.top()]<=price[i])
        {
            st.pop();
        }
        if(st.empty()){
            prev_greater[i]=-1;
        }
        else
        {
            prev_greater[i]=st.top();
        }
        st.push(i);
        ans.push_back(i-prev_greater[i]);
    }
    return ans;
}