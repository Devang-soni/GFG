/*
Find out the maximum sub-array of non negative numbers from an array.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:
a = [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length.
If there is still a tie, then return the segment with minimum starting index.
If no such subarray is present return "-1"

Examples:

Input:
n = 3
a[] = {1, 2, 3}
Output: 1 2 3
Explanation: In the given array every
element is non-negative.
Input:
n = 2
a[] = {-1, 2}
Output: 2
Explanation: The only subarray [2] is
the answer.

*/

class Solution {
  public:
    vector<int> findSubarray(int n, int a[]) {
        vector<int>ans;
        int start = 0 ,s=0,e=0;
        int sum=0;
        int mxlen = INT_MIN ;
        int mxsum = INT_MIN;
        for(int i=0;i<n;i++){
            if(a[i]>=0){
                sum+=a[i];
                if(sum>mxsum){
                    e=i;
                    start =s;
                    mxsum=sum;
                    mxlen = max(mxlen,e-s+1);
                }
                else if(sum==mxsum){
                    if((i-s+1)>mxlen){
                        e=i;
                        start = s;
                        mxsum=sum;
                        mxlen =max(mxlen,e-s+1);
                    }
                }
            }
            else{
                s=i+1;
                sum=0;
            }
        }
        for(int i=start;i<=e;i++) ans.push_back(a[i]);
        if(ans.size()==0) return {-1};
        return ans;
    }   
    
};


