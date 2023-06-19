//https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-sorted-array_8230811?challengeSlug=striver-sde-challenge&leftPanelTab=1

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int c=1;
        for (int i = 0; i < n-1; i++) {
			if(arr[i]!=arr[i+1])
			c++;
        }
		return c;
}