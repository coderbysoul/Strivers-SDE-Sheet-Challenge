//https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_8230805?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> triangle(n);
    
    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    
    return triangle;
}
