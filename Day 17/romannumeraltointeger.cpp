//https://www.codingninjas.com/studio/problems/roman-numeral-to-integer_8230780?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
int romanToInt(string s) {
    // Write your code here

    map<char,int>charToInt;

    charToInt['I']=1;
    charToInt['V']=5;
    charToInt['X']=10;
    charToInt['L']=50;
    charToInt['C']=100;
    charToInt['D']=500;
    charToInt['M']=1000;

    int n=s.size();

    int result = charToInt[s.back()];

    for(int i=n-2;i>=0;i--)
    {
        if(charToInt[s[i]]<charToInt[s[i+1]])
          result-=charToInt[s[i]] ;
         else
          result+=charToInt[s[i]]; 
    }
 return result;
}
