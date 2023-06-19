//https://www.codingninjas.com/codestudio/problems/maximum-meetings_8230795?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
static bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.second.second != b.second.second)
        return (a.second.second < b.second.second);
    return (a.first < b.first);
}

vector<int> maximumMeetings(vector<int>& start, vector<int>& end) {
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < start.size(); i++) {
        v.push_back({ i,{ start[i],end[i] } });
    }
    sort(v.begin(), v.end(), cmp);
    int count = 1;
    int ansEnd = v[0].second.second;
    vector<int> meetingno;
    meetingno.push_back(v[0].first + 1);

    for (int i = 1; i < start.size(); i++) {
        if (v[i].second.first > ansEnd) {
            ansEnd = v[i].second.second;
            count++;
            meetingno.push_back(v[i].first + 1);
        }
    }
    return meetingno;
}
