//https://www.codingninjas.com/studio/problems/rabin-carp_8230831?challengeSlug=striver-sde-challenge&leftPanelTab=1

vector<int> stringMatch(string text, string pattern) {
    int n = pattern.size();
    vector<int> ans;

    for (int i = 0; i < text.size(); i++) {
        if (text[i] == pattern[0] && (i + n - 1) < text.size()) {
            string str = text.substr(i, n);
            if (str == pattern) {
                ans.push_back(i + 1);
            }
        }
    }

    return ans;
}
