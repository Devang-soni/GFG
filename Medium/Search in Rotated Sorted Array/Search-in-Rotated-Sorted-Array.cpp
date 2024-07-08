/*
Given a sorted (in ascending order) and rotated array arr of distinct elements which may be rotated at some point and given an element key, the task is to find the index of the given element key in the array arr. The whole array arr is given as the range to search.

Rotation shifts elements of the array by a certain number of positions, with elements that fall off one end reappearing at the other end.

Note:- 0-based indexing is followed & returns -1 if the key is not present.

Examples :

Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 10
Output: 5
Explanation: 10 is found at index 5.
Input: arr[] = [3, 5, 1, 2], key = 6
Output: -1
Explanation: There is no element that has value 6.
*/

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int n=arr.size();
        int s= 0 , e=n-1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(arr[mid]==key)
            {
                return mid;
            }
            else if(arr[s]<=arr[mid])
            {
                if(arr[mid]>key && arr[s]<=key)
                {
                     e=mid-1;
                   
                }
                else
                    s=mid+1;
            }
            else if(arr[mid]<=arr[e])
            {
                if(arr[mid]<key && key<=arr[e])s=mid+1;
                else
                    e=mid-1;
            }
            
        }
        return -1;
    }
};
