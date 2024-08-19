/*
Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array. It is given that all array elements are distinct.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output:  7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [7, 10, 4, 20, 15], k = 4 
Output:  15
Explanation: 4th smallest element in the given array is 15.
*/

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        priority_queue<int> pq;
        int n=arr.size();
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        for(int i=k; i<n; i++){
            if(arr[i] <pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
        
    }
};
