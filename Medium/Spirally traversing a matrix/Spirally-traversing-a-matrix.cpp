/*
You are given a rectangular matrix, and your task is to return an array while traversing the matrix in spiral form.

Examples:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12],
                  [13, 14, 15,16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
Explanation:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12]]
Output: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
Explanation: Applying same technique as shown above, output for the 2nd testcase will be 1 2 3 4 8 12 11 10 9 5 6 7.
*/


int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m-1;
        int top = 0, bottom = n-1;

    vector<int> ans;

    while(top<=bottom && left <= right){


        for(int i=left; i<=right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top; i<=bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom){
            for(int i=right; i>=left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if(left <= right){
            for(int i=bottom; i>=top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
    }
