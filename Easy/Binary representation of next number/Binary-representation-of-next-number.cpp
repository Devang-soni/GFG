/*
Given a binary representation in the form of a string(s) of a number n, the task is to find a binary representation of n+1.

Note: Output binary string should not contain leading zeros.

Example 1:

Input: s = "10"
Output: 11
Explanation: "10" is the binary representation of 2 and binary representation of 3 is "11"
Example 2:

Input: s = "111"
Output: 1000
Explanation: "111" is the binary representation of 7 and binary representation of 8 is "1000"

*/

class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int n = s.size();
        int i=n-1,j=0;
        for(j;j<n-1;j++) if(s[j]!='0') break;
        s=s.substr(j);
        i-=j;
        while(i>=0){
            if(s[i]=='1') s[i--]='0';
            else{
                s[i] = '1';
                return s;
            }
        }
        return '1'+ s;
    }
};
