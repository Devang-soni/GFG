/*
Given an array arr of n integers. Your task is to write a program to find the maximum value of ∑arr[i]*i, where i = 0, 1, 2,., n-1. You are allowed to rearrange the elements of the array.

Note: Since the output could be large, print the answer modulo 109+7.

Examples :

Input : arr[] = [5, 3, 2, 4, 1]
Output : 40
Explanation: If we arrange the array as 1 2 3 4 5 then we can see that the minimum index will multiply with minimum number and maximum index will multiply with maximum number. So, 1*0 + 2*1 + 3*2 + 4*3 + 5*4 = 0+2+6+12+20 = 40 mod(109+7) = 40

Input : arr[] = [1, 2, 3]
Output : 8
*/

class Solution {
  public:
    int Maximize(vector<int> &arr) {
        // Complete the function
        sort(arr.begin(), arr.end());
        long long int sum = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i<arr.size(); i++){
            sum += (1ll*i*arr[i]);
            sum %= mod;
        }
        return sum;
    }
};
