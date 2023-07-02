//https://www.codingninjas.com/studio/problems/largest-rectangle-in-a-histogram_8230792?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    int maxArea = 0;
    int area;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            area = height * width;
            maxArea = max(maxArea, area);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int height = heights[s.top()];
        s.pop();
        int width = s.empty() ? n : n - s.top() - 1;
        area = height * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}
