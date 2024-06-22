/*
Given a sentence containing several words and numbers. Find the largest number among them which does not contain 9. If no such number exists, return -1.

Note: Numbers and words are separated by spaces only. It is guaranteed that there are no leading zeroes in the answer.

Examples :

Input: sentence="This is alpha 5057 and 97"
Output: 5057
Explanation: 5057 is the only number that does not have a 9.
Input: sentence="Another input 9007"
Output: -1
Explanation: Since there is no number that does not contain a 9,output is -1.
*/

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        long long ans=0, temp=0;
        bool indi=false;
        for (char x:sentence){
            if(x>='0' && x<='9'){
                temp=temp*10+(x-'0');
                if(x=='9') indi=true;
            }
            else if(x==' '){
                if(!indi){
                ans=max(ans,temp);}
                temp=0;
                indi=false;
            }
        }
        if(!indi)  ans=max(ans,temp);
        return ans==0?-1:ans;
    }
};
