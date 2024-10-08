/*
Given an array nums[], construct a Product Array nums[] such that nums[i] is equal to the product of all the elements of nums except nums[i].

Examples:

Input: nums[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]
Explanation: For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
Input: nums[] = [12,0]
Output: [0, 12]
*/

// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int n = nums.size();
        vector<long long int> ans;
        vector<long long int>pre(n+1), post(n+1);
        pre[0] = 1;
        for(int i = 1; i<=n; i++){
            pre[i] = pre[i-1] * nums[i-1];
        }
        post[n] = 1;
        for(int i = n-1; i>=0; i--){
            post[i] = post[i+1] * nums[i];
        }
        // for(auto it : pre)cout<<it<<" ";
        // cout<<endl;
        // for(auto it : post)cout<<it<<" ";
        // cout<<endl;
        for(int i = 0; i<n; i++){
            ans.push_back(pre[i] * post[i+1]);
        }
        return ans;
    }
};
