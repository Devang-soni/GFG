/*
Given an array arr of integers. Find whether three numbers are such that the sum of two elements equals the third element.

Example:

Input: arr[] = [1, 2, 3, 4, 5]
Output: true
Explanation: The pair (1, 2) sums to 3.
Input: arr[] = [5, 3, 4]
Output: false
Explanation: No triplets satisfy the condition.
*/


class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int sz = arr.size();
        for(int i = sz - 1; i >= 0; i--){
            int ele = arr[i];
            int lw = 0;
            int hg = i - 1;
            while(lw < hg){
                if(arr[lw] + arr[hg] == ele){
                    return true;
                }else if(arr[lw] + arr[hg] > ele){
                    hg--;
                }else{
                    lw++;
                }
            }
        }
        return false;
    }
};
