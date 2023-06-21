//https://www.codingninjas.com/studio/problems/kth-smallest-and-largest-element-of-array_8230829?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	vector<int>ans;
	sort(arr.begin(),arr.end());

	int kthSmallest = arr[k - 1];
    int kthLargest = arr[n - k];

    ans.push_back(kthSmallest);
    ans.push_back(kthLargest);

	return ans;
}