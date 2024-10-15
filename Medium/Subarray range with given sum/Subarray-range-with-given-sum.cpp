/*
Given an unsorted array of integers arr[], and a target tar, determine the number of subarrays whose elements sum up to the target value.

Examples:

Input: arr[] = [10, 2, -2, -20, 10] , tar = -10
Output: 3
Explanation: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].
Input: arr[] = [1, 4, 20, 3, 10, 5] , tar = 33
Output: 1
Explanation: Subarray with sum 33 is: [20,3,10].

*/

class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
      
       unordered_map<int,int>map;
          
          int currsum = 0; 
          
          int count  = 0; 
          for(int i = 0; i< arr.size(); i++){
              currsum+=arr[i];
              if(currsum == tar){
                  count++; 
              }
              int diff  = currsum-tar; 
              if(map.find(diff)!= map.end()){
                  count+=map[diff]; 
              }
                map[currsum]++;    
          }
          
          return count;   // Your code here
    }
};
