/*
Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

Examples:

Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
Output: 22
Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
Output: 23
Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
Input: arr[] = [-1, 40, -14, 7, 6, 5, -4, -1] 
Output: 52
Explanation: Circular Subarray [7, 6, 5, -4, -1, -1, 40] has the maximum sum, which is 52.
*/
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int big = INT_MIN, sum = 0, curr=0;
        for(int i = 0; i<arr.size(); ++i)
        {
            curr += arr[i];
            sum += arr[i];
            big = max(big, curr);
            
            if(curr < 0)
                curr = 0;
        }
        curr = 0;
        for(int i = 0; i<arr.size(); ++i)
        {
            curr += arr[i];
            big = max(big, sum - curr);
            
            if(curr > 0)
                curr = 0;
        }
        return big;
    }
};
