//https://www.codingninjas.com/codestudio/problems/merge-two-sorted-arrays_8230835?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <vector>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    
    vector<int> merged(m + n);

    int i = 0; 
    int j = 0; 
    int k = 0; 

    
    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    
    while (i < m) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    
    while (j < n) {
        merged[k] = arr2[j];
        j++;
        k++;
    }

   
    return merged;
}
