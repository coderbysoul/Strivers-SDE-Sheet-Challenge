//https://www.codingninjas.com/studio/problems/check-permutation_8230834?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    unordered_map<int,int> mp;
    unordered_map<int,int> ump;

    for(int i=0;i<str1.size();i++)
    {
        mp[str1[i]]++;
    }

    if(str2.size()!=str1.size())
    {
        return false;
    }

    for(int i=0;i<str1.size();i++)
    {
        ump[str2[i]]++;
    }

    for(int i=0;i<str2.size();i++)
    {
        int count=mp[str1[i]];
        if(count>ump[str1[i]]){
            return false;
        }
    }
    return true;
}