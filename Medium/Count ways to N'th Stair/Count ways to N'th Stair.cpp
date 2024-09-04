/*
There are n stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
Note: Order does not matter means for n = 4:- {1 2 1},{2 1 1},{1 1 2} are considered same.

Examples :

Input: n = 4
Output: 3
Explanation: Three ways to reach at 4th stair. They are {1, 1, 1, 1}, {1, 1, 2}, {2, 2}.
Input: n = 5
Output: 3
Explanation: Three ways to reach at 5th stair. They are {1, 1, 1, 1, 1}, {1, 1, 2, 1} and {1, 2, 2}.


*/

class Solution{
	public:
	    int dp[10001];
	    int solve(int n){
	        if(n==0||n==1)return n;
	        if(dp[n]!=-1)return dp[n];
	        int a=(solve(n-1));
	        int b=(solve(n-2));
	        return dp[n]= 1+ min(a,b);
	    }
		int nthStair(int n){
		    memset(dp,-1,sizeof(dp));
		    return n%2==0?solve(n)+1:solve(n);
		}
};
