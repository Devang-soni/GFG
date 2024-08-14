/*
You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: str1 = "ABCDGH", str2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.
Input: str1 = "ABC", str2 = "ACB"
Output: 1
Explanation: The longest common substrings are "A", "B", "C" all having length 1
*/
class Solution{
    public:
    
    int longestCommonSubstr(string S1, string S2)
    {
        int n = S1.size();
        int m = S2.size();
        vector<vector<int>>dp(n + 1 , vector<int>(m  + 1 , 0));
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j <= m ; j++){
                if(S1[i - 1] == S2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans , dp[i][j]);
                }
            }
        }
        return ans;
    }
