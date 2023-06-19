//https://www.codingninjas.com/codestudio/problems/reverse-words-in-a-string_8230698?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <vector>
#include <string>
using namespace std;

string reverseString(string str) {
    vector<string> words;
    string temp = "";
    
    for (char c : str) {
        if (c == ' ') {
            if (!temp.empty()) { // Only add non-empty words
                words.push_back(temp);
                temp = "";
            }
        }
        else {
            temp += c;
        }
    }
    if (!temp.empty()) { // Add the last word
        words.push_back(temp);
    }
    
    reverse(words.begin(), words.end()); // Reverse the order of words
    
    string ans = "";
    for (int i = 0; i < words.size(); i++) {
        ans += words[i];
        if (i != words.size() - 1) {
            ans += " ";
        }
    }
    
    return ans;
}

