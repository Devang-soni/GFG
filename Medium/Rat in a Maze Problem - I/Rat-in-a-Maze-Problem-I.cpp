/*
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

Examples:

Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0],
                [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.


*/


class Solution {
  public:
    void solve(vector<vector<int>> &mat,vector<string> &ans,int i, int j,int n,int m,
                                                                            string x){
        if(i>=n || j>=m || i<0 || j<0 || mat[i][j]==0){
            return ;
        }
        if(i==n-1 && j==n-1){
            ans.push_back(x);
            return;
        }
        mat[i][j]=0;
        solve(mat,ans,i+1,j,n,m,x+'D');
        solve(mat,ans,i,j+1,n,m,x+'R');
        solve(mat,ans,i-1,j,n,m,x+'U');
        solve(mat,ans,i,j-1,n,m,x+'L');
        
        mat[i][j]=1;
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> ans;
        int n=mat.size(),m=mat[0].size();
        string x="";
        solve(mat,ans,0,0,n,m,x);
        return ans;
        
    }
};
