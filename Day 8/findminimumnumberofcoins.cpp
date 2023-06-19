//https://www.codingninjas.com/codestudio/problems/find-minimum-number-of-coins_8230766?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
int findMinimumCoins(int amount) {
    
    int v[9] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
    int i = 8; 

    int c = 0;
    while (amount > 0) {
        if (v[i] <= amount) {
            int coinsNeeded = amount / v[i];
            c += coinsNeeded;
            amount -= coinsNeeded * v[i];
        }
        i--;
    }
    return c;
}
