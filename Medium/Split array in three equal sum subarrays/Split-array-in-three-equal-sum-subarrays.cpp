/*
Given an array, arr[], determine if arr can be split into three consecutive parts such that the sum of each part is equal. If possible, return any index pair(i, j) in an array such that sum(arr[0..i]) = sum(arr[i+1..j]) = sum(arr[j+1..n-1]), otherwise return an array {-1,-1}.

Note: Since multiple answers are possible, return any of them. The driver code will print true if it is correct otherwise, it will print false.

Examples :

Input:  arr[] = [1, 3, 4, 0, 4]
Output: true
Explanation: [1, 2] is valid pair as sum of subarray arr[0..1] is equal to sum of subarray arr[2..3] and also to sum of subarray arr[4..4]. The sum is 4. 
Input: arr[] = [2, 3, 4]
Output: false
Explanation: No three subarrays exist which have equal sum.
Input: arr[] = [0, 1, 1]
Output: false
*/

class Solution {
  public:
    vector<int> findSplit(vector<int>& arr) {
        int sm= accumulate(arr.begin(),arr.end(),0); 
        if(sm%3!=0) return {-1,-1};
        sm= sm/3; 
        int cur=0;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            if(cur+arr[i]<=sm){
                
                cur+=arr[i];
                if(cur==sm){
                    ans.push_back(i);
                cur=0;
                }
            }
            else return {-1,-1};
        }
        ans.pop_back();  
        return ans;
    }
};
