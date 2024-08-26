/*
Given two strings pattern and str which may be of different size, You have to return 1 if the wildcard pattern i.e. pattern, matches with str else return 0. All characters of the string str and pattern always belong to the Alphanumeric characters.

The wildcard pattern can include the characters ? and *
‘?’ – matches any single character.
‘*’ – Matches any sequence of characters (including the empty sequence).

Note: The matching should cover the entire str (not partial str).

Examples:

Input: pattern = "ba*a?", str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and 
'?' with 'b'.
Input: pattern = "a*ab", str = "baaabab"
Output: 0
Explanation: Because in string pattern character 'a' at first position,
pattern and str can't be matched. 
*/


class Solution {
public:
    int wildCard(string pattern, string str) {
        // Get the lengths of the pattern and the string
        int n = pattern.size();
        int m = str.size();

        // Create a 2D DP array initialized with 0
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Iterate over the pattern and string in reverse order
        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                
                // Case 1: Both pattern and string are fully traversed
                if (i == n && j == m) {
                    dp[i][j] = 1;
                }
                
                // Case 2: Pattern is fully traversed, but string is not
                else if (i == n) {
                    dp[i][j] = 0;
                }
                
                // Case 3: String is fully traversed, but pattern is not
                else if (j == m) {
                    if (pattern[i] == '*') {
                        // '*' can match an empty sequence
                        dp[i][j] = dp[i+1][j];
                    } else {
                        dp[i][j] = 0;
                    }
                }
                
                // Case 4: Compare characters of pattern and string
                else {
                    if (pattern[i] == str[j]) {
                        // Characters match, move both pointers
                        dp[i][j] = dp[i+1][j+1];
                    } 
                    else if (pattern[i] == '?') {
                        // '?' matches any single character
                        dp[i][j] = dp[i+1][j+1];
                    } 
                    else if (pattern[i] == '*') {
                        // '*' can match an empty sequence or any sequence
                        dp[i][j] = dp[i+1][j] || dp[i][j+1];
                    } 
                    else {
                        // Characters do not match
                        dp[i][j] = 0;
                    }
                }
            }
        }
        
        // Return the result for the entire strings
        return dp[0][0];
    }
};

