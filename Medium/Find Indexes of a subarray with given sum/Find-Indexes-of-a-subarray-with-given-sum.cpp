/*
Given an unsorted array arr of size n that contains only non negative integers, find a sub-array (continuous elements) that has sum equal to s. You mainly need to return the left and right indexes(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. If no such subarray exists return an array consisting of element -1.

Examples:

Input: arr[] = {1,2,3,7,5}, n = 5, s = 12
Output: 2 4
Explanation: The sum of elements from 2nd to 4th position is 12.
Input: arr[] = {1,2,3,4,5,6,7,8,9,10}, n = 10, s = 15,
Output: 1 5
Explanation: The sum of elements from 1st to 5th position is 15.
*/
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        int l=0,r=0;
        int sum=0;
        while(r<n)
        {
            sum+=arr[r];
            
            while(sum>s && l<r)
            {
                sum-=arr[l++];
            }
            
            if(sum==s) return {l+1,r+1};
            
            r++;
            
        }
        return {-1};
    }
};
