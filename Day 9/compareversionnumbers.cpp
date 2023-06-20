//https://www.codingninjas.com/studio/problems/compare-version-numbers_8230793?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    int i = 0, j = 0;
    int alen = a.size(), blen = b.size();
     
    
    while (i < alen || j < blen) {
        long long n1 = 0;
        long long n2 = 0;
        
        while (i < alen && a[i] != '.') {
            n1 = n1 * 10 + (a[i] - '0');
            i++;
        }
        
        while (j < blen && b[j] != '.') {
            n2 = n2 * 10 + (b[j] - '0');
            j++;
        }
        
        if (n1 < n2)
            return -1;
        else if (n1 > n2)
            return 1;
        
        if (i < alen)
            i++;
        
        if (j < blen)
            j++;
    }
    
    return 0;
}