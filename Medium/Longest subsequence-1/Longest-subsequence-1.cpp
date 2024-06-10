/*
Given an integer array a[] of size n, find the length of the longest subsequence such that the absolute difference between adjacent elements is 1.

Example 1:

Input:
n = 7
a[] = {10, 9, 4, 5, 4, 8, 6}
Output: 
3
Explaination: 
The three possible subsequences of length 3 are {10, 9, 8}, {4, 5, 4}, and {4, 5, 6}, where adjacent elements have a absolute difference of 1. No valid subsequence of greater length could be formed.
Example 2:

Input: 
n = 5
a[] = {1, 2, 3, 4, 5}
Output: 
5
Explaination: 
All the elements can be included in the valid subsequence.
*/
class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
        vector<int> b(n,1);
        int ans=0;
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(abs(a[i]-a[j])==1){
                    b[i]=max(b[i],1+b[j]);
                    ans=max(ans,b[i]);
                }
            }
        }
        return ans;
    }
};


