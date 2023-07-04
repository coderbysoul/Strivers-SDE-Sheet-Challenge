//https://www.codingninjas.com/studio/problems/implement-atoi-function_8230776?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int n=str.length();
    bool neg=false;
    string ans="";
    for(int i=0;i<n;i++)
    {
        if(str[i]=='-')
         neg=true;
        if(str[i]<65 && str[i]!='-') {
            ans=ans+str[i];
        }
    }
    if(neg==true)
    return -stoi(ans);
    return stoi(ans);
}