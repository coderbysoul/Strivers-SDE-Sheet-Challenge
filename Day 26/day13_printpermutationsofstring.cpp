//https://www.codingninjas.com/studio/problems/day-13-print-permutations-string_8230703?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
void solve(string s,vector<string>&answer,int index)
{
    if(index>=s.size())
    {
        answer.push_back(s);
        return;
    }
    for (int i = index; i < s.size(); i++) {
        swap(s[index],s[i]);
        solve(s,answer,index+1);
        swap(s[index],s[i]);
    }
}

vector<string> findPermutations(string& s) {
    vector<string>answer;
    int index=0;
    solve(s,answer,index);
    return answer;
}
