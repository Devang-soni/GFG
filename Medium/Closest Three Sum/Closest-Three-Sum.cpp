/*
Given an array, arr of integers, and another number target, find three integers in the array such that their sum is closest to the target. Return the sum of the three integers.

Note: If there are multiple solutions, return the maximum one.

Examples :

Input: arr[] = [-7, 9, 8, 3, 1, 1], target = 2
Output: 2
Explanation: There is only one triplet present in the array where elements are -7,8,1 whose sum is 2.
Input: arr[] = [5, 2, 7, 5], target = 13
Output: 14
Explanation: There is one triplet with sum 12 and other with sum 14 in the array. Triplet elements are 5, 2, 5 and 2, 7, 5 respectively. Since abs(13-12) ==abs(13-14) maximum triplet sum will be preferred i.e 14.
*/

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        
        int prevDiff = INT_MAX;
        int closestSum = INT_MIN;
        for(int i = 0; i < arr.size() - 2; i++){
            int start = i + 1; 
            int end = arr.size() - 1;
            while(start < end){
                int sum = arr[i] + arr[start] + arr[end];
                if(sum == target) return sum;
                int currentDiff = abs(sum - target);
                if(currentDiff < prevDiff || (currentDiff == prevDiff && sum > closestSum)){
                    prevDiff = currentDiff;
                    closestSum = sum;
                }
                if(sum < target){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return closestSum;
    }
};
