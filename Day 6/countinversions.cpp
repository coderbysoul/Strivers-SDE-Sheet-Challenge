//https://www.codingninjas.com/codestudio/problems/count-inversions_8230680?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, int low, int mid, int high) {
    long long inversions = 0;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    long long left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
            inversions += n1 - i; // Count inversions
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    return inversions;
}

long long mergeSort(long long *arr, int low, int high) {
    long long inversions = 0;

    if (low < high) {
        int mid = low + (high - low) / 2;

        inversions += mergeSort(arr, low, mid);
        inversions += mergeSort(arr, mid + 1, high);

        inversions += merge(arr, low, mid, high);
    }

    return inversions;
}

long long getInversions(long long *arr, int n) {
    return mergeSort(arr, 0, n - 1);
}

