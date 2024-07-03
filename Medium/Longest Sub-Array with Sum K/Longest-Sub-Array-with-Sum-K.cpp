/*
Given an array arr containing n integers and an integer k. Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k.


Examples:
 

Input :
arr[] = {10, 5, 2, 7, 1, 9}, k = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Input : 
arr[] = {-1, 2, 3}, k = 6
Output : 0
Explanation: 
There is no such sub-array with sum 6.
*/

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        map<int, int> countMap;
        int sum = 0;
        int ans = 0;
        for(int i=0; i<N; i++){
            sum += A[i];
            if(sum == K){
                ans = max(ans, i+1);
            }
            if(countMap.find(sum) == countMap.end()){
                countMap[sum] = i;
            }
            if(countMap.find(sum - K) != countMap.end()){
                ans = max(ans, i - countMap[sum - K]);
            }
        }
        return ans;
    }
};
