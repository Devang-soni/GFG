/*
Given 2 sorted integer arrays arr1 and arr2 of the same size. Find the sum of the middle elements of two sorted arrays arr1 and arr2.

Examples:

Input: arr1 = [1, 2, 4, 6, 10], arr2 = [4, 5, 6, 9, 12]
Output: 11
Explanation: The merged array looks like [1, 2, 4, 4, 5, 6, 6, 9, 10, 12]. Sum of middle elements is 11 (5 + 6).
Input: arr1 = [1, 12, 15, 26, 38], arr2 = [2, 13, 17, 30, 45]
Output: 32
Explanation: The merged array looks like [1, 2, 12, 13, 15, 17, 26, 30, 38, 45]. Sum of middle elements is 32 (15 + 17).
*/

class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        
        int n = arr1.size();
        int m = arr2.size();
        
        int low = 0;
        int high = n;
        int left = (n + m + 1)/2;
        
        while(low<=high){
            int mid1 = (low+high)/2;
            int mid2 = left-mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if(mid1<n){
                r1 = arr1[mid1];
            }
            if(mid2<m){
                r2 = arr2[mid2];
                
            }
            if(mid1-1>=0){
                l1 = arr1[mid1-1];
            }
            if(mid2-1>=0){
                l2 = arr2[mid2-1];
            }
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2) + min(r1,r2);
            }
            else if(l1>r2){
                high = mid1-1;
            }
            else if(l2>r1){
                low = mid1+1;
            }
        }
        return -1;
    }
};
