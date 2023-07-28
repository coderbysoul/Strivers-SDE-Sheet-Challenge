//https://www.codingninjas.com/studio/problems/next-greater-element_8230718?challengeSlug=striver-sde-challenge&leftPanelTab=1



#include <bits/stdc++.h> 


vector<int> nextGreater(vector<int>& arr, int n) {
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty()) {
            if (st.top() > arr[i]) {
                res[i] = st.top();
                break;
            }
            st.pop();
        }
        st.push(arr[i]);
    }

    return res;
}
