/*
Given a string s without spaces, a character ch and an integer count. Your task is to return the substring that remains after the character ch has appeared count number of times.
Note:  Assume upper case and lower case alphabets are different. “”(Empty string) should be returned if it is not possible, or the remaining substring is empty.

Examples:

Input: s = "Thisisdemostring", ch = 'i', count = 3
Output: ng
Explanation: The remaining substring of s after the 3rd
occurrence of 'i' is "ng", hence the output is ng.
Input: s = "Thisisdemostri", ch = 'i', count = 3
Output: ""
Explanation: The 3rd occurence of 'i' is at the last index. In this case the remaining substring is empty, hence we return empty string.
Input: s = "abcd", ch = 'x', count = 2
Output: ""
Explanation: The character x is not present in the string, hence we return empty string.
*/

class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        int n=s.length();
        int c=0;
        for(int i=0;i<n;i++){
            
            if(s[i]==ch){
                c+=1;
            }
            if(c==count){
                return(s.substr(i+1,n-i-1));
            }
        }
        return("");
    }
};

