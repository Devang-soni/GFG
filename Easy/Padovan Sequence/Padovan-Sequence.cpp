/*
Given a number n, find the nth number in the Padovan Sequence.

A Padovan Sequence is a sequence which is represented by the following recurrence relation
P(n) = P(n-2) + P(n-3)
P(0) = P(1) = P(2) = 1

Note: Since the output may be too large, compute the answer modulo 10^9+7.

Examples :

Input: n = 3
Output: 2
Explanation: We already know, P1 + P0 = P3 and P1 = 1 and P0 = 1
Input: n = 4
Output: 2
Explanation: We already know, P4  = P2 + P1 and P2 = 1 and P1 = 1
*/

class Solution {
  public:
    int padovanSequence(int n) {
        int mod = 1e9+7;
    
        if(n<=2)
            return 1;
        int a = 1, b=1, c=1;
        for(int i=3;i<=n;i++){
            int val =(a+b)%mod;
            a=b,b=c,c=val;  
        }
        return c;
    }
};
