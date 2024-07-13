/*
Given an array arr[], with index ranging from 0 to n-1, select any two indexes, i and j such that i < j . From the subarray arr[i...j], select the two minimum numbers and add them, you will get the score for that subarray. Return the maximum possible score across all the subarrays of array arr[].
 

Examples :

Input : arr[] = [4, 3, 1, 5, 6]
Output : 11
Explanation : Subarrays with smallest and second smallest are:- [4, 3] smallest = 3,second smallest = 4
[4, 3, 1] smallest = 1, second smallest = 3
[4, 3, 1, 5] smallest = 1, second smallest = 3
[4, 3, 1, 5, 6] smallest = 1, second smallest = 3
[3, 1] smallest = 1, second smallest = 3
[3, 1, 5] smallest = 1, second smallest = 3
[3, 1, 5, 6] smallest = 1, second smallest = 3
[1, 5] smallest = 1, second smallest = 5
[1, 5, 6] smallest = 1, second smallest = 5
[5, 6] smallest = 5, second smallest = 6
Maximum sum among all above choices is, 5 + 6 = 11.
Input : arr[] = [5, 4, 3, 1, 6] 
Output : 9
*/

class Solution {
  public:
    long long pairWithMaxSum(long long arr[], long long N) {
        // Your code goes here
        long long maxi = INT_MIN;
        for(int i=1; i<N; i++){
            maxi = max(maxi, arr[i-1] + arr[i]);
            
        }
        return maxi;
    }
};


