//https://www.codingninjas.com/studio/problems/maximum-activities_8230800?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>

bool compareByFinish(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

int maximumActivities(std::vector<int>& start, std::vector<int>& finish) {
    std::vector<std::pair<int, int>> activities; // Pair of start and finish values

    // Combine the two arrays into a vector of pairs
    for (int i = 0; i < start.size(); i++) {
        activities.push_back(std::make_pair(start[i], finish[i]));
    }

    // Sort the activities based on the finish values
    std::sort(activities.begin(), activities.end(), compareByFinish);

    int n = activities.size();
    int count = 1; // Keep track of the maximum activities
    int prevFinish = activities[0].second;

    // Traverse through the sorted activities
    for (int i = 1; i < n; i++) {
        // If the start time of the current activity is greater than or equal to the previous finish time
        // Then it can be performed, so increment the count and update the previous finish time
        if (activities[i].first >= prevFinish) {
          count++;
          prevFinish = activities[i].second;
        }
    }
    return count;
}