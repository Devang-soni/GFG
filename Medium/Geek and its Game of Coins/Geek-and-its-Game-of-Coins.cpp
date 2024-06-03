/*
Given three numbers n, x, and y, Geek and his friend are playing a coin game. In the beginning, there are n coins. In each move, a player can pick x, y, or 1 coin. Geek always starts the game. The player who picks the last coin wins the game. The task is to determine whether Geek will win the game or not if both players play optimally.

Example 1:

Input: 
n = 5
x = 3
y = 4
Output: 
1
Explanation:
There are 5 coins, every player can pick 1 or 3 or 4 coins on his/her turn. Geek can win by picking 3 coins in first chance. Now 2 coins will be left so his friend will pick one coin and now Geek can win by picking the last coin.
Example 2:
Input:
n = 2
x = 3
y = 4
Output:
0
Explanation: 
Geek picks 1 coin and then his friend picks 1 coin.
*/

class Solution {
  public:
    int findWinner(int n, int x, int y) {
        bool dp[n+1]={false};
        for(int i=1;i<=n;i++)
            dp[i]=(i>=1 && !dp[i-1]) || (i>=x && !dp[i-x]) || (i>=y && !dp[i-y]); 
        return dp[n];
    }
};
