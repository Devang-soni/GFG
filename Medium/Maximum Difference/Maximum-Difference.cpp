/*
Given an integer array arr of integers, the task is to find the maximum absolute difference between the nearest left smaller element and the nearest right smaller element of every element in array arr. If for any component of the arr, the nearest smaller element doesn't exist then consider it as 0.

Examples :

Input: arr = [2, 1, 8]
Output: 1
Explanation: left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1
Input: arr = [2, 4, 8, 7, 7, 9, 3]
Output: 4
Explanation: left smaller array ls = [0, 2, 4, 4, 4, 7, 2], right smaller rs = [0, 3, 7, 3, 3, 3, 0]. Maximum Diff of abs(ls[i] - rs[i]) = abs(7 - 3) = 4

*/

class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        stack<int> st, st1;
        
        st.push(arr[0]);
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        for(int i=1; i< n; i++){
            while(!st.empty() && arr[i] <= st.top()){
                st.pop();
            }
            if(!st.empty()){
                left[i] = st.top();
            }
            st.push(arr[i]);
        }
        st1.push(arr[n-1]);
        for(int i=n-2; i>=0; i--){
            while(!st1.empty() && arr[i] <= st1.top()){
                st1.pop();
            }
            if(!st1.empty()){
                right[i] = st1.top();
            }
            st1.push(arr[i]);
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n;i++){
            ans = max(ans, abs(left[i] - right[i]));
        }
        return ans;
    }
};
