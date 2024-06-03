/*
Given a number n, find the number of binary strings of length n that contain consecutive 1's in them. Since the number can be very large, return the answer after modulo with 1e9+7.

Example 1:

Input: n = 2
Output: 1
Explanation: There are 4 strings of length 2, the strings are 00, 01, 10, and 11. Only the string 11 has consecutive 1's.
Example 2:

Input: n = 3
Output: 3
Explanation: There are 8 strings of length 3, the strings are 000, 001, 010, 011, 100, 101, 110 and 111.  The strings with consecutive 1's are 011, 110 and 111.
*/
class Solution {

 public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        if(n==2)
            return 1;
        int a=0, b=1, c, mod=1e9+7, ans=1;
        for(int i=3; i<=n; i++)
        {
            int c=(a+b)%mod;
            a=b;
            b=c;
            ans=((ans*2)%mod+c)%mod;
        }
        return ans;
    }
}; 
