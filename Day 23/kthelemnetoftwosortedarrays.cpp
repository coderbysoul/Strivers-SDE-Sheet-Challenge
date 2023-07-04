//https://www.codingninjas.com/studio/problems/kth-element-of-two-sorted-arrays_8230824?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
 int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
      if(row1.size()>row2.size()){
           swap(row1,row2); swap(n,m);
            } 
            int l = max(0,k-n); 
            int r = min(k-1,m);
             while(true){ 
                 int mid = (l+r)/2; 
                 int A = mid==m?INT_MAX:row1[mid];
                  int B = k-1-mid==n?INT_MAX:row2[k-1-mid]; 
                  int ALeft = mid==0?INT_MIN:row1[mid-1]; 
                  int BLeft = k-mid-1==0?INT_MIN:row2[k-mid-2];
                   if(ALeft<=B&&BLeft<=A){ 
                       return min(A,B); 
                       } else if(ALeft>B){
                            r = mid-1;
                       } else {
                         l = mid + 1;
                       }
             }
 }