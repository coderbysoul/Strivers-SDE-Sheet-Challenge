//https://www.codingninjas.com/studio/problems/valid-parentheses_8230714?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <iostream>
#include <stack>
#include <unordered_map>

bool isValidParenthesis(string expression) {
    stack<char> stk;
    unordered_map<char, char> matchingParentheses = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty() || stk.top() != matchingParentheses[c]) {
                return false;
            }
            stk.pop();
        }
    }

    return stk.empty();
}