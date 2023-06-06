//https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_8230694?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>


long long maxSubarraySum(int arr[], int n)

{

    long long sum=0;

    long long maxi=arr[0];

 

    for(int i=0;i<n;i++){

        sum+=arr[i];

        maxi=max(maxi,sum);

 

        if(sum<0){

            sum=0;

        }

    }

 

    if(maxi<0 )

        return 0;

    else

        return maxi;

}