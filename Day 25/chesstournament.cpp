//https://www.codingninjas.com/studio/problems/chess-tournament_8230779?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

bool check(long long dis, std::vector<int> &arr, int c, int n) {
    int player = 1;
    long long pre_pos = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] - pre_pos >= dis) {
            pre_pos = arr[i];
            player++;
        }
        if (player == c)
            return true;
    }
    return false;
}

int chessTournament(std::vector<int> positions, int n, int c) {
    std::sort(positions.begin(), positions.end());
    long long i = 0;
    long long j = positions[n - 1] - positions[0];
    long long ans = -1;
    while (i <= j) {
        long long m = i + (j - i) / 2;
        if (check(m, positions, c, n)) {
            i = m + 1;
            ans = m;
        } else
            j = m - 1;
    }
    return ans;
}
