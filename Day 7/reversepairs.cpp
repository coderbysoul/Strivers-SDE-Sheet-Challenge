//https://www.codingninjas.com/codestudio/problems/reverse-pairs_8230825?challengeSlug=striver-sde-challenge&leftPanelTab=1

int merge(vector<int> &arr, int left, int mid, int right) {
    int count = 0;

    
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if ((long long)arr[i] > 2LL * arr[j]) {
            count += mid - i + 1;
            j++;
        } else {
            i++;
        }
    }

    
    vector<int> temp;
    i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }

    return count;
}

int mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;
    int count = mergeSort(arr, left, mid) + mergeSort(arr, mid + 1, right) + merge(arr, left, mid, right);
    return count;
}

int reversePairs(vector<int> &arr, int n) {
    return mergeSort(arr, 0, n - 1);
}
