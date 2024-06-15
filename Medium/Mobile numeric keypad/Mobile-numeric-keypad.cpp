/*
There is a standard numeric keypad on a mobile phone. You can only press the current button or buttons that are directly up, left, right, or down from it (for ex if you press 5, then pressing 2, 4, 6 & 8 are allowed). Diagonal movements and pressing the bottom row corner buttons (* and #) are prohibited.

Given a number n, find the number of possible unique sequences of length n that you can create by pressing buttons. You can start from any digit.

Examples

Input: n = 1
Output: 10
Explanation: Number of possible numbers are 10 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)  
Input: n = 2
Output: 36
Explanation: Possible numbers: 00, 08, 11, 12, 14, 22, 21, 23, 25 and so on. If we start with 0, valid numbers will be 00, 08 (count: 2). If we start with 1, valid numbers will be 11, 12, 14 (count: 3). If we start with 2, valid numbers  will be 22, 21, 23,25 (count: 4). If we start with 3, valid numbers will be 33, 32, 36 (count: 3). If we start with 4, valid numbers will be 44,41,45,47 (count: 4). If we start with 5, valid numbers will be 55,54,52,56,58 (count: 5) and so on.
*/

class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        
         vector<long long int>pre(10,1);   
        
        for(int i=2;i<=n;i++){
            vector<long long int>curr(10,0); 
            for(int i=1;i<=9;i++){
                curr[i]+=pre[i]; 
                if(i-1>0 && (i-1)%3!=0){
                    curr[i]+=pre[i-1];
                }
                if(i+1<10 && (i+1)%3!=1 ){
                    curr[i]+=pre[i+1];
                    
                }
                if(i-3>0){
                    curr[i]+=pre[i-3];
                }
                if(i+3<10){
                    curr[i]+=pre[i+3];
                }
            }
            curr[0]=pre[8]+pre[0]; 
            curr[8]+=pre[0];

            pre=curr;
            
        }
        long long int ans=0;
        for(int i=0;i<=9;i++){
            ans+=pre[i];
        }
        return ans;


    }
};
