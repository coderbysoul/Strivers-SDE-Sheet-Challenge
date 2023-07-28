//https://www.codingninjas.com/studio/problems/minimum-characters-for-palindrome_8230737?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
int minCharsforPalindrome(string str)
{
int n=str.size();
int i=0;
int j=n-1;
int k=j;

while(j>=i)
{
    if(str[i]!=str[j]){
        i=0;
        k--;
        j=k;
    }
    else
    {
        j--;
        i++;
    }
}
return n-1-k;
}