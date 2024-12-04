/*
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Examples :

Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: After 2 right rotations, s1 will become equal to s2.
Input: s1 = "aab", s2 = "aba"
Output: true
Explanation: After 1 left rotation, s1 will become equal to s2.
Input: s1 = "abcd", s2 = "acbd"
Output: false
Explanation: Strings are not rotations of each other.
*/

class Solution {    
  public:
    bool areRotations(string &s1, string &s2) {
        if(s1.length()!=s2.length())return false;
        int i=0,j=0,count=0,flag=0;
        while(i<s1.length()){
            if(j>=s2.length())j=j%s2.length();
            if(s1[i]!=s2[j])j++;
            if(s1[i]==s2[j]){i++;j++;}
            count++;
            if(count>=2*s1.length()){flag=1;break;}
        }
        return flag==0;
    }
};
