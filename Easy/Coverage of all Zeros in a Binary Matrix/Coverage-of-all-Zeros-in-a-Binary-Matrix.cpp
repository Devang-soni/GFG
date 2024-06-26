/*
Given a binary matrix contains 0s and 1s only, we need to find the sum of coverage of all zeros of the matrix where coverage for a particular 0 is defined as a total number of ones around a zero in left, right, up and bottom directions.

Examples:

Input:
matrix = [[0, 1, 0],
          [0, 1, 1],
          [0, 0, 0]]
Output: 6
Explanation: There are a total of 6 coverage are there

Input: 
matrix = [[0, 1]]
Output: 1
Explanation: There are only 1 coverage.
*/


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int total_coverage = 0;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                if (i > 0 && matrix[i-1][j] == 1) {
                    total_coverage += 1;
                }
                if (i < rows-1 && matrix[i+1][j] == 1) {
                    total_coverage += 1;
                }
                if (j > 0 && matrix[i][j-1] == 1) {
                    total_coverage += 1;
                }
                if (j < cols-1 && matrix[i][j+1] == 1) {
                    total_coverage += 1;
                }
            }
        }
    }
    
    return total_coverage;
    }
};
