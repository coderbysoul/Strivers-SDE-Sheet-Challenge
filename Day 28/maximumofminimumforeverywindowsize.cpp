//https://www.codingninjas.com/studio/problems/maximum-of-minimum-for-every-window-size_8230783?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

vector<int> lse(vector<int>& a, int n) {
    stack<int> st;
    vector<int> ans(n, -1); // Initialize ans vector with -1
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> rse(vector<int>& a, int n) {
    stack<int> st;
    vector<int> ans(n, n); // Initialize ans vector with n
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> LSE = lse(a, n);
    vector<int> RSE = rse(a, n);
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = RSE[i] - LSE[i] - 1;
    }
    vector<int> ans(n, -1000000000);
    for (int i = 0; i < n; i++) {
        ans[temp[i] - 1] = max(ans[temp[i] - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    return ans;
}
