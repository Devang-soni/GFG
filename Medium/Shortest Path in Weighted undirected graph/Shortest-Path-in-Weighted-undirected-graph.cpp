/*
You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1. 

Examples :

Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
Output: 5
Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 
Input: n = 2, m= 1, edges = [[1, 2, 2]]
Output: 2
Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2. 
Input: n = 2, m= 0, edges = [ ]
Output: -1
Explanation: Since there are no edges, so no answer is possible.
*/

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int, int>>> adj(n + 1);

        for(int i = 0; i < m; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            int z = edges[i][2];
    
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
        }
    
        set<pair<int, int>> st;
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
        vector<int> dist(n + 1, 1e9);
        dist[1] = 0;
        st.insert({0, 1});
    
        while(!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
    
            for(auto it: adj[node]) {
                int d = it.second;
                int y = it.first;
                if(dist[y] > dis + d) {
                    dist[y] = dis + d;
                    parent[y] = node;
                    st.insert({dist[y], y});
                }
            }
        }
    
        if (dist[n] == 1e9) return {-1};
    
        int temp = n;
        vector<int> ans;
        while(parent[temp]!=temp) {
            ans.push_back(temp);
            temp = parent[temp];
        }
        ans.push_back(1);
        ans.push_back(dist[n]);
        reverse(ans.begin(), ans.end());
    
        return ans;
    }
};
