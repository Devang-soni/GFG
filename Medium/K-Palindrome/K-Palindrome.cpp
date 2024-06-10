/*
Given a string str of length n, find if the string is K-Palindrome or not. A k-palindrome string transforms into a palindrome on removing at most k characters from it.

Example 1:

Input: str = "abcdecba"
n = 8, k = 1
Output: 1
Explaination: By removing 'd' or 'e' 
we can make it a palindrome.

Example 2:
Input: str = "abcdefcba"
n = 9, k = 1
Output: 0
Explaination: By removing a single 
character we cannot make it a palindrome.
*/

class Solution{
public:
    int kPalindrome(string str1, int n, int k)
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string str2 = str1;
        reverse(str2.begin(),str2.end());
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n]>=n-k;
    }
};
