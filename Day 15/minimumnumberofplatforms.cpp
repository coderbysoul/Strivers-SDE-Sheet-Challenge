//https://www.codingninjas.com/studio/problems/minimum-number-of-platforms_8230720?challengeSlug=striver-sde-challenge&leftPanelTab=1

int calculateMinPatforms(int at[], int dt[], int n) {
    // Sort the arrival and departure times in ascending order
    sort(at, at + n);
    sort(dt, dt + n);

    int platforms = 1; // Minimum number of platforms required
    int minPlatforms = 1; // Minimum number of platforms required at any point

    int i = 1; // Pointer for arrival times
    int j = 0; // Pointer for departure times

    // Merge the arrival and departure times similar to merge process of merge sort
    while (i < n && j < n) {
        if (at[i] <= dt[j]) {
            platforms++; // Increment platforms if a train arrives
            i++;
        } else {
            platforms--; // Decrement platforms if a train departs
            j++;
        }

        minPlatforms = max(minPlatforms, platforms); // Update the minimum platforms required
    }

    return minPlatforms;
}
