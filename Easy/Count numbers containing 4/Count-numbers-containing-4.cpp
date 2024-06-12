/*
You are given a number n, Return the count of total numbers from 1 to n containing 4 as a digit.

Examples:

Input: n = 9
Output: 1
Explanation: 4 is the only number between 1 to 9 which contains 4 as a digit.
Input: n = 44
Output: 9
Explanation: 4, 14, 24, 34, 40, 41, 42, 43 & 44, there are total 9 numbers containing 4 as a digit.
*/

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int ans=0;
        
        for(int i=4;i<=n;i++){
            int j=i;
            while(j){
                if(j%10==4){
                    ans++;
                    break;
                }
                 j/=10;
            }
           
        }
        return ans;
    }
};
