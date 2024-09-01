/*
Given two sorted arrays of distinct integers arr1 and arr2. Each array may have some elements in common with the other array. Find the maximum sum of a path from the beginning of any array to the end of any array. You can switch from one array to another array only at the common elements.

Note:  When we switch from one array to other,  we need to consider the common element only once in the result.

Examples : 

Input: arr1 = [2, 3, 7, 10, 12] , arr2 = [1, 5, 7, 8]
Output: 35
Explanation: The path will be 1+5+7+10+12 = 35, where 1 and 5 come from arr2 and then 7 is common so we switch to arr1 and add 10 and 12.
Input: arr1 = [1, 2, 3] , arr2[] = [3, 4, 5]
Output: 15
Explanation: The path will be 1+2+3+4+5=15.
*/


class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int i = arr1.size()-1, j = arr2.size()-1;
        
        int max_path = 0, arr1_path = 0, arr2_path = 0;
        
        while(i >= 0 && j >= 0)
            if(arr1[i] > arr2[j])
                arr1_path += arr1[i--];
            else if(arr1[i] < arr2[j])
                arr2_path += arr2[j--];
            else
            {
                max_path += max(arr1_path + arr1[i--], arr2_path + arr2[j--]);
                arr1_path = arr2_path = 0;
            }
        
        while(i >= 0)
            arr1_path += arr1[i--];
        while(j >= 0)
            arr2_path += arr2[j--];
        
        max_path += max(arr1_path, arr2_path);
        
        return max_path;
    }
};
