//https://www.codingninjas.com/studio/problems/job-sequencing-problem_8230832?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 

bool compare(std::vector<int>& job1, std::vector<int>& job2) {
    return job1[1] > job2[1]; // Sort jobs based on profit in descending order
}

int jobScheduling(std::vector<std::vector<int>>& jobs) {
    int n = jobs.size();

    // Sort jobs based on profit in descending order
    std::sort(jobs.begin(), jobs.end(), compare);

    std::vector<bool> slot(n, false); // Array to track available slots
    std::vector<int> result(n, -1); // Array to store selected jobs

    for (int i = 0; i < n; i++) {
        // Find an available slot starting from the deadline of the job
        for (int j = std::min(n, jobs[i][0]) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true; // Mark the slot as occupied
                result[j] = i; // Store the job index in the result array
                break;
            }
        }
    }

    int totalProfit = 0;

    // Calculate the total profit by summing the profits of selected jobs
    for (int i = 0; i < n; i++) {
        if (result[i] != -1) {
            totalProfit += jobs[result[i]][1];
        }
    }

    return totalProfit;
}