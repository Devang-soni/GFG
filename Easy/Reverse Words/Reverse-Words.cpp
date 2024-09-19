/*
Given a String str, reverse the string without reversing its individual words. Words are separated by dots.

Note: The last character has not been '.'. 

Examples :

Input: str = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i
Input: str = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole string , the input string becomes mno.pqr

*/


class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        
        int len = str.size();
        string ans;
        string temp;
        
        for(int i=0; i<len; i++){
            if(str[i] == '.'){
                ans ='.' + temp + ans;
                temp = "";
                
            }
            else{
                temp += str[i];
            }
            
        }
        ans = temp + ans;
            
        return ans;
    }
};
