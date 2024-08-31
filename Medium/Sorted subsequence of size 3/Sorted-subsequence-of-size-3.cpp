/*
You are given an array arr, you need to find any three elements in it such that arr[i] < arr[j] < arr[k] and i < j < k.

Note:

The output will be 1 if the subsequence returned by the function is present in the array arr
If the subsequence is not present in the array then return an empty array, the driver code will print 0.
If the subsequence returned by the function is not in the format as mentioned then the output will be -1.
Examples :

Input: arr = [1, 2, 1, 1, 3]
Output: 1
Explanation: A subsequence 1 2 3 exist.
Input: arr = [1, 1, 3]
Output: 0
Explanation: No such Subsequence exist, so empty array is returned (the driver code automatically prints 0 in this case).

*/


class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        
        if(arr.size() < 3) return {};
        // Code here
        int n = arr.size();
        int left[n] = {0};
        int right[n] = {0};
        
        int leftMin = arr[0];
        for(int i = 1; i < n; i++) {
            left[i] = leftMin;
            leftMin = min(leftMin, arr[i]);
        }
      
        int rightMax = arr[n-1];
        for(int i = n-2; i >= 0; i--) {
            right[i] = rightMax;
            rightMax = max(rightMax, arr[i]);
        }
      
        for(int i = 1; i <= n-2; i++) {
            if(left[i] < arr[i] and right[i] > arr[i]) return {left[i], arr[i], right[i]};
        }
        
        return {};
    }
};
