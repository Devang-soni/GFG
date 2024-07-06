/*
Given an array arr of non-negative numbers. The task is to find the first equilibrium point in an array. The equilibrium point in an array is an index (or position) such that the sum of all elements before that index is the same as the sum of elements after it.

Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

Examples:

Input: arr[] = [1, 3, 5, 2, 2]
Output: 3 
Explanation: The equilibrium point is at position 3 as the sum of elements before it (1+3) = sum of elements after it (2+2). 
Input: arr[] = [1]
Output: 1
Explanation: Since there's only one element hence it's only the equilibrium point.
Input: n = 3, arr[] = [1, 2, 3]
Output: -1
Explanation: There is no equilibrium point in the given array.
*/

class Solution {
  public:
    // Function to find equilibrium point in the array.
    // arr: input array
    int equilibriumPoint(vector<long long> &arr) {
        int sum=0;
        int n=arr.size();
        for(int t=0;t<n;t++){
           sum=sum+arr[t];
        }int sum4=0;
        for(int t=0,h=1;t<n;t++,h++){
            
             sum-=arr[t];
            if(sum==sum4){
                return h;
                
            }sum4=sum4+arr[t];
        }return -1;
    }
};


