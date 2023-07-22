//https://www.codingninjas.com/studio/problems/longest-substring-without-repeating-characters_8230684?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int e=-1;
    int largest=0;
    vector<int>charpos(26,-1);
    for(int i=0;i<input.length();i++)
    {
        int pos=input[i]-'a';
        if(e<charpos[pos])
        e=charpos[pos];
        charpos[pos]=i;
        largest=max(largest,i-e);
    }
    return largest;
}