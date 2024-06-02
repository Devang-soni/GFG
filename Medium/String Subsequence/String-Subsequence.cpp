/*
Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.

Return the total count modulo 1e9+7.

Example 1:

Input: s1 = geeksforgeeks, s2 = gks
Output: 4
Explaination: We can pick characters from s1 as a subsequence from indices {0,3,4}, {0,3,12}, {0,11,12} and {8,11,12}.So total 4 subsequences of s1 that are equal to s2.
Example 2:

Input: s1 = problemoftheday, s2 = geek
Output: 0
Explaination: No subsequence of string s1 is equal to string s2.
*/

class Solution {
  public:
        int mod = 1e9+7;
    int solve(string &s1, string &s2,int i,int j,vector<vector<int>>&dp)
    {
        if(j < 0)
          return 1;
        if(i < 0)
          return 0;
        if( dp[i][j] != -1 )
          return dp[i][j];
        if( s1[i] == s2[j] )
          return dp[i][j] = (solve(s1,s2,i-1,j-1,dp)%mod + solve(s1,s2,i-1,j,dp)%mod)%mod;
        else
          return dp[i][j] = solve(s1,s2,i-1,j,dp)%mod;
    }
    int countWays(string s1, string s2) {
        // code here
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,n-1,m-1,dp);
    }
};
