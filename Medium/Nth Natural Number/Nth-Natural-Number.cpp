/*
Given a positive integer n. You have to find nth natural number after removing all the numbers containing the digit 9.

Examples :

Input: n = 8
Output: 8
Explanation: After removing natural numbers which contains digit 9, first 8 numbers are 1,2,3,4,5,6,7,8 and 8th number is 8.
Input: n = 9
Output: 10
Explanation: After removing natural numbers which contains digit 9, first 9 numbers are 1,2,3,4,5,6,7,8,10 and 9th number is 10.

*/

class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        ll ans = 0,p = 1;
        while(n){
            ans = (n%9)*p + ans;
            n /= 9;
            p *= 10;
        }
        return ans;
    }
};
