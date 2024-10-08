/*
Find the largest pair sum in an array of distinct integers.

Examples :

Input: arr[] = [12, 34, 10, 6, 40]
Output: 74
Explanation: Sum of 34 and 40 is the largest, i.e, 34 + 40 = 74.
Input: arr[] = [10, 20, 30]
Output: 50
Explanation: 20 + 30 = 50.

*/

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int max_ind1 = 0, max_ind2 = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > arr[max_ind1]) max_ind1 = i;
        }
        max_ind2 += (max_ind1 == 0 ? 1 : 0);
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > arr[max_ind2] && i != max_ind1) max_ind2 = i;
        }
        
        return arr[max_ind1] + arr[max_ind2];
    }
};
