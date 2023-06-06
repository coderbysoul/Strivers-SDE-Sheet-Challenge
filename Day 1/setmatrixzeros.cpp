//https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_8230862?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    
    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    
    for (int col = 0; col < cols; ++col) {
        if (matrix[0][col] == 0) {
            firstRowHasZero = true;
            break;
        }
    }

    
    for (int row = 0; row < rows; ++row) {
        if (matrix[row][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }

   
    for (int row = 1; row < rows; ++row) {
        for (int col = 1; col < cols; ++col) {
            if (matrix[row][col] == 0) {
                matrix[0][col] = 0;
                matrix[row][0] = 0;
            }
        }
    }

    
    for (int row = 1; row < rows; ++row) {
        if (matrix[row][0] == 0) {
            for (int col = 1; col < cols; ++col) {
                matrix[row][col] = 0;
            }
        }
    }

    
    for (int col = 1; col < cols; ++col) {
        if (matrix[0][col] == 0) {
            for (int row = 1; row < rows; ++row) {
                matrix[row][col] = 0;
            }
        }
    }

   
    if (firstRowHasZero) {
        for (int col = 0; col < cols; ++col) {
            matrix[0][col] = 0;
        }
    }

    
    if (firstColHasZero) {
        for (int row = 0; row < rows; ++row) {
            matrix[row][0] = 0;
        }
    }
}
