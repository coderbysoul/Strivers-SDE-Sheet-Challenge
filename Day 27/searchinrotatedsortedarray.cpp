//https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_8230687?challengeSlug=striver-sde-challenge&leftPanelTab=1

int search(int* arr, int n, int key) {
    int i = 0;
    int j = n - 1;

    while (i <= j) {
        int mid = i + (j - i) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        // If the left half is sorted
        if (arr[i] <= arr[mid]) {
            if (arr[i] <= key && key < arr[mid]) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        // If the right half is sorted
        else {
            if (arr[mid] < key && key <= arr[j]) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
    }

    return -1;
}
