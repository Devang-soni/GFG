/*
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.

*/

class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int large = -1;
        
        int slarge = -1;
        for(int i=0; i<arr.size(); i++){
            if(large<arr[i]){
                slarge = large;
                large = arr[i];
            }
            else if(large>arr[i] && slarge<arr[i]){
                slarge = arr[i];
            }
        }
        return slarge;
    }
};
