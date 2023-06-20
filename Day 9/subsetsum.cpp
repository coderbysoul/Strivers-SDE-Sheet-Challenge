//https://www.codingninjas.com/studio/problems/subset-sum_8230859?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
void func(int ind,int sum,vector<int>&arr,int N,vector<int>&sumSubset)
{
  if(ind==N){
      sumSubset.push_back(sum);
      return;
  }

  //pick the element
  func(ind+1,sum+arr[ind],arr,N,sumSubset);

  //Do not pick the element
  func(ind+1,sum,arr,N,sumSubset);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int>ans;
    func(0,0,num,num.size(),ans);
    sort(ans.begin(),ans.end());
    return ans;
    
}