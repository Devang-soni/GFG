/*
Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 

Examples:

Input: mat[][] = [[1, 2, 3],
                [4, 5, 6]
                [7, 8, 9]]
Output: Rotated Matrix:
[3, 6, 9]
[2, 5, 8]
[1, 4, 7]
Input: mat[][] = [[1, 2],
                [3, 4]]
Output: Rotated Matrix:
[2, 4]
[1, 3]
*/

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        for(int cir=0,n=mat.size();cir<(n+1)/2;cir++)
        for(int i=cir;i<n-cir-1;i++)
        {
            int temp = mat[i][n-cir-1];
            mat[i][n-cir-1] = mat[n-cir-1][n-1-i];
            mat[n-cir-1][n-1-i] = mat[n-1-i][cir];
            mat[n-1-i][cir] = mat[cir][i];
            mat[cir][i] = temp;
        }
    
    }
};
