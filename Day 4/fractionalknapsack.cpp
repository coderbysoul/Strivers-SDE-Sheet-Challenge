//https://www.codingninjas.com/codestudio/problems/fractional-knapsack_8230767?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 

bool compare(const pair<int, int>& p1, const pair<int, int>& p2)
{
    // Compare the value/weight ratios of the pairs
    double ratio1 = static_cast<double>(p1.second) / p1.first;
    double ratio2 = static_cast<double>(p2.second) / p2.first;
    return ratio1 > ratio2;
}

double maximumValue(vector<pair<int, int>>& items, int n, int w)
{
    // Sort the items based on the value/weight ratio in decreasing order
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;  // Total value accumulated so far
    int currentWeight = 0;    // Current weight in the knapsack

    for (int i = 0; i < n; i++)
    {
        // If the current item can be fully included in the knapsack
        if (currentWeight + items[i].first <= w)
        {
            currentWeight += items[i].first;
            totalValue += items[i].second;
        }
        else
        {
            // Calculate the fraction of the item to include
            double remainingWeight = w - currentWeight;
            double fraction = static_cast<double>(remainingWeight) / items[i].first;
            totalValue += fraction * items[i].second;
            break;
        }
    }

    return totalValue;
}
