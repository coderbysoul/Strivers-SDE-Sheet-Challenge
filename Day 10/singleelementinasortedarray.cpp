//https://www.codingninjas.com/studio/problems/single-element-in-a-sorted-array_8230826?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <vector>

int singleNonDuplicate(const std::vector<int>& arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (mid % 2 == 1)
            mid--;  // Ensure mid is an even index

        if (arr[mid] == arr[mid + 1])
            left = mid + 2;
        else
            right = mid;
    }

    return arr[left];
}
