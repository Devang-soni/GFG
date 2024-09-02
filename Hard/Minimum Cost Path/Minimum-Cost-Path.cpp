/*
Given a square grid of size N, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a path from the top left cell to the bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).  

Examples :

Input: grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.
Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.
*/

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        if(n == 1 && m == 1) return grid[0][0];
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({grid[0][0], 0});
        
        while(!pq.empty()) {
            int curr = pq.top().first;
            int i = pq.top().second/m, j = pq.top().second%m;
            pq.pop();
            
            if(i + 1 < n && dist[i + 1][j] > curr + grid[i + 1][j]) {
                dist[i + 1][j] = curr + grid[i + 1][j];
                int nex = (i + 1)*m + j;
                pq.push({dist[i + 1][j], nex});
            }
            if(i - 1 >= 0 && dist[i - 1][j] > curr + grid[i - 1][j]) {
                dist[i - 1][j] = curr + grid[i - 1][j];
                int nex = (i - 1)*m + j;
                pq.push({dist[i - 1][j], nex});
            }
            if(j + 1 < m && dist[i][j + 1] > curr + grid[i][j + 1]) {
                dist[i][j + 1] = curr + grid[i][j + 1];
                int nex = (i)*m + j + 1;
                pq.push({dist[i][j + 1], nex});
            }
            if(j - 1 >= 0 && dist[i][j - 1] > curr + grid[i][j - 1]) {
                dist[i][j - 1] = curr + grid[i][j - 1];
                int nex = (i)*m + j - 1;
                pq.push({dist[i][j - 1], nex});
            }
        }
        return dist[n - 1][m - 1];
    }
};
