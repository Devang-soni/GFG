/*
A string str is given to represent a positive number. The task is to round str to the nearest multiple of 10.  If you have two multiples equally apart from str, choose the smallest element among them.

Examples:

Input: str = 29 
Output: 30
Explanation: Close multiples are 20 and 30, and 30 is the nearest to 29. 
Input: str = 15
Output: 10
Explanation: 10 and 20 are equally distant multiples from 20. The smallest of the two is 10.

*/

class Solution {
  public:
    string roundToNearest(string str) {
        int n=str.length();
        if(str[n-1]<='5')
        {
            str[n-1]='0';
            return str;
        }
        str[n-1]='0';
        int i=n-2;
        while(i>=0 && str[i]=='9')
        {
            str[i]='0';
            i--;
        }
        if(i<0) return '1'+str;
        else str[i]++;
        return str;
    }
};

