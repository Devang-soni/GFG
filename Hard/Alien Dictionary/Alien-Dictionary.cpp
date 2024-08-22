/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

Examples :

Input:  N = 5, K = 4, dict = {"baa","abcd","abca","cab","cad"}
Output: 1
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Input: N = 3, K = 3, dict = {"caa","aaa","aab"}
Output: 1
Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
*/

class Solution {
  public:
    void dfs(int cur,unordered_map<int,list<int>>&adj,vector<bool>&vis,stack<int>&st){
        vis[cur]=1;
        for(auto i:adj[cur]){
            if(!vis[i]){
                dfs(i,adj,vis,st);
                st.push(i);
            }
        }
        return;
    }
    string findOrder(string dict[], int n, int k) {
        unordered_map<int,list<int>>adj;
        vector<int>inDegree(k);
        for(int i=0;i<n-1;i++){
            int len=min(dict[i].length(),dict[i+1].length());
            for(int j=0;j<len;j++){
                if(dict[i][j]!=dict[i+1][j]){
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    inDegree[dict[i+1][j]-'a']++;
                    break;
                }
            }
        }
        vector<bool>vis(k);
        stack<int>st;
        for(int i=0;i<k;i++){
            if(inDegree[i]==0 && !vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        string ans="";
        while(!st.empty()){
            int temp=st.top();
            ans+=('a'+temp);
            st.pop();
        }
        return ans;
    }
};
