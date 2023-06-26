//https://www.codingninjas.com/studio/problems/maximum-consecutive-ones_8230736?challengeSlug=striver-sde-challenge&leftPanelTab=1

int longestSubSeg(vector<int> &arr, int n, int k) {
    int maxLength = 0; // Maximum length of consecutive ones
    int zeroCount = 0; // Count of zeros in the current window
    int i = 0; // Start of the current window

    for (int j = 0; j < n; j++) {
        if (arr[j] == 0) {
            zeroCount++;
        }

        // Shrink the window until the number of zeros is <= k
        while (zeroCount > k) {
            if (arr[i] == 0) {
                zeroCount--;
            }
            i++;
        }

        maxLength = max(maxLength, j - i + 1);
    }

    return maxLength;
}
