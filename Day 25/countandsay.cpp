//https://www.codingninjas.com/studio/problems/count-and-say_8230807?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

string writeAsYouSpeak(int n) {
    if (n == 1) {
        return "1";
    }

    n--;
    string s = "1";
    while (n--) {
        char c = s[0];
        string z;
        int ct = 0, i = 0;
        while (i < s.size()) {
            while (i < s.size() && c == s[i]) {
                i++;
                ct++;
            }
            if (i < s.size() && c != s[i]) {
                z += (ct + '0');
                z += c;
                c = s[i];
                ct = 0;
            } else if (i == s.size()) {
                z += (ct + '0');
                z += c;
                break;
            }
        }
        s = z;
    }

    return s;
}
