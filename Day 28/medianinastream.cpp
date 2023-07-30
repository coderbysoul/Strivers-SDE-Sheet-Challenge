//https://www.codingninjas.com/studio/problems/median-in-a-stream_8230765?challengeSlug=striver-sde-challenge&leftPanelTab=1

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	vector<int>ans;
	for(int i=0;i<arr.size();i++)
	{
		int key=arr[i];
		int j=i-1;

		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;

		int size=i+1;
		if(size%2==0)
		{
			ans.push_back(0.5*(arr[(size-1)/2]+arr[(size+1)/2]));
		}
		else
		{
			ans.push_back(arr[size/2]);
		}
	}
	return ans;
}
