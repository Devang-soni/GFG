/*
Given two strings x and y, and two values costX and costY, the task is to find the minimum cost required to make the given two strings identical. You can delete characters from both the strings. The cost of deleting a character from string X is costX and from Y is costY. The cost of removing all characters from a string is the same.

Example 1:
Input: x = "abcd", y = "acdb", costX = 10 
       costY = 20.
Output: 30
Explanation: For Making both strings 
identical we have to delete character 
'b' from both the string, hence cost 
will be = 10 + 20 = 30.
Example 2:

Input : x = "ef", y = "gh", costX = 10
        costY = 20.
Output: 60
Explanation: For making both strings 
identical, we have to delete 2-2 
characters from both the strings, hence 
cost will be = 10 + 10 + 20 + 20 = 60.
*/
class Solution {

  public:
    int findMinCost(string x, string y, int costX, int costY) {
        int n1 =x.size();
        int n2 =y.size();
        vector<vector<int>> dp(n1+ 1,vector<int> (n2 +1));
        dp[0][0] =0;
        for(int i =1;i<=n1;i++){
            for(int j =1;j<=n2;j++){
                if(x[i -1] == y[j -1]){
                    dp[i][j] = 1+ dp[i -1][j -1];
                }
                else{
                    dp[i][j] = max(dp[i -1][j],dp[i][j -1]);
                }
            }
        }
        
        int LCS =dp[n1][n2];
        return costX*(n1 - LCS) + costY*(n2 - LCS);
    }
};




