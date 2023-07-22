//https://www.codingninjas.com/studio/problems/return-subsets-sum-to-k_8230706?challengeSlug=striver-sde-challenge&leftPanelTab=1

void takeorNotTake(vector<vector<int>>&superSet, vector<int>arr, vector<int>ans,int n, int k, int i)
{
    if(i==n)
    {
        if(k==0)
        {
            superSet.push_back(ans);
        }
        return;
    }
    takeorNotTake(superSet, arr,  ans,  n,  k,  i+1);
    ans.push_back(arr[i]);

    takeorNotTake(superSet,  arr,  ans,  n,  k-arr[i],  i+1);
return;
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>>superSet;
    vector<int>ans;

    takeorNotTake(superSet,  arr,  ans,  n,  k,  0);
    return superSet;
   
}