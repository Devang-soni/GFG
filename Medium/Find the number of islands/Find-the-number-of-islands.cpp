/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:


Input: grid = [[0,1],[1,0],[1,1],[1,0]]
Output: 1
Explanation:
The grid is-

All lands are connected.
Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
Output: 2
Expanation:
The grid is-
 
There are two islands :- one is colored in "blue" and other in "red".

*/

class Solution {
  public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0},  {0, 1},  {0, -1},
                                {1, 1},  {-1, 1}, {1, -1}, {-1, -1}};
    void dfs(vector<vector<char>>& grid, int i, int j,
             vector<vector<int>>& vis) {
        vis[i][j] = true;
        for (auto dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];

            if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ||
                vis[x][y] || grid[x][y] == '0')
                continue;

            dfs(grid, x, y, vis);
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here

        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == false) {
                    ans++;
                    dfs(grid, i, j, vis);
                }
            }
        }
        return ans;
    }
};
