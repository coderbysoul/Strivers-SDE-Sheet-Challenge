//https://www.codingninjas.com/studio/problems/power-set_8230797?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 


void func(int ind, vector<int>& num, vector<int>& current, vector<vector<int>>& ans)
{
    if (ind == num.size()) {
        ans.push_back(current);
        return;
    }

    // Exclude the current element
    func(ind + 1, num, current, ans);

    // Include the current element
    current.push_back(num[ind]);
    func(ind + 1, num, current, ans);

    // Backtrack by removing the current element
    current.pop_back();
}

vector<vector<int>> pwset(vector<int>& num)
{
    vector<vector<int>> ans;
    vector<int> current;
    func(0, num, current, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
