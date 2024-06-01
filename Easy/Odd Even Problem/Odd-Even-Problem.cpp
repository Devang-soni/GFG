/*
  Given a string s of lowercase English characters, determine whether the summation of x and y is EVEN or ODD.
where:

x is the count of distinct characters that occupy even positions in the English alphabet and have even frequency. 
y is the count of distinct characters that occupy odd positions in the English alphabet and have odd frequency.
Ex: string = "ab" here 'a' has an odd(1) position in the English alphabet & has an odd(1) frequency in the string so a is odd but b has an even(2) position in the English alphabet & has odd(1) frequency so it doesn't count(since string doesn't have 2 b's) so the final answer x + y = 1+0 = 1(odd) would be "ODD".

Note: Return "EVEN" if the sum of x & y is even otherwise return "ODD".
  */

class Solution {
  public:
    string oddEven(string s) {
        int temp[26];
    memset(temp,0,sizeof temp);
    int x=0,y=0;
    for(int i=0;i<s.length();i++)
        temp[s[i]-'a']++;
        for(int i=0;i<26;i++){
            if((i+1)%2){
                if(temp[i]%2)y++;
            }
            else{
                if(temp[i]%2==0 and temp[i])x++;
            }
        }
        return (x+y)%2==1?"ODD":"EVEN";
    }
};
