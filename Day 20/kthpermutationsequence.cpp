//https://www.codingninjas.com/studio/problems/k-th-permutation-sequence_8230822?challengeSlug=striver-sde-challenge&leftPanelTab=1

string kthPermutation(int n, int k) {
    // Write your code here.
    vector<int>nums;
    for(int i=1;i<=n;i++)
    {
        nums.push_back(i);
    }
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }

    std::string result;
    k--;

    for (int i = n; i >= 1; i--) {
        fact /= i;

        int index = k / fact;
        k %= fact;

        result += std::to_string(nums[index]);
        nums.erase(nums.begin() + index);
    }

    return result;
}





