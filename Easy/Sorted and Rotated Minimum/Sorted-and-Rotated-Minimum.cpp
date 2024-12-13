/*
A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 

Examples:

Input: arr[] = [5, 6, 1, 2, 3, 4]
Output: 1
Explanation: 1 is the minimum element in the array.
Input: arr[] = [3, 1, 2]
Output: 1
Explanation: Here 1 is the minimum element.
Input: arr[] = [4, 2, 3]
Output: 2
Explanation: Here 2 is the minimum element.

*/

class Solution {
  public:
    int findMin(vector<int>& arr) {
         int n=arr.size(),low=0,high=n-1,mid=0;
        while(low<high){
            mid=(low+high)/2;
            if(arr[mid]<=arr[high])high=mid;
            else low=mid+1;
        }
        return arr[low];
    }
};
