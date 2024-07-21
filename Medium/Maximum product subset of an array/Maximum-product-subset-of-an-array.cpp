/*
Given an array arr. The task is to find and return the maximum product possible with the subset of elements present in the array.

Note:

The maximum product can be a single element also.
Since the product can be large, return it modulo 109 + 7.
Examples:

Input: arr[] = [-1, 0, -2, 4, 3]
Output: 24
Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24
Input: arr[] = [-1, 0]
Output: 0
Explanation: Maximum product will be ( -1 * 0) = 0
Input: arr[] = [5]
Output: 5
Explanation: Maximum product will be 5.
*/

class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        
        int n =arr.size();
        int neg = 0, zero = 0, negt =-1e9;
        long long int prod = 1;
        int mod = 1e9+7;
        
        for(int i=0; i<n;i++){
            if(arr[i] == 0) zero++;
            else if(arr[i] < 0){
                neg++;
                negt = max(negt, arr[i]);
                prod *= arr[i];
            }
            
            else{
                prod *= arr[i];
            }
            prod%= mod;
        }
        
        if(zero == n) return 0;
        if(neg == 1 && zero==n-1) return 0;
        if(neg%2==0) return prod;
        if(neg%2==1) prod = prod/negt;
        
        return prod;
        
    }
};

