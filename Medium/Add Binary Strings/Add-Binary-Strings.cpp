/*
Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110
*/
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string result = "";
        int i = s1.size() - 1, j = s2.size() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry){
            int bit1 = (i >= 0) ? s1[i--] - '0' : 0;
            int bit2 = (j >= 0) ? s2[j--] - '0' : 0;
            int sum = bit1 + bit2 + carry;

            result += (sum % 2) + '0';  
            carry = sum / 2;           
        }

        reverse(result.begin(), result.end()); 

        int count=0;
        while(result[count]=='0'){
            count++;
        }
        result.erase(0,count++);
        return result;
    }
};
