/*
You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
 

Example 1:

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
Example 2:

Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not
integer.
*/


class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int low=1,high=m;
	    while(low<=high){
	        int mid=(low+high)/2;
	        if(pow(mid,n)==m){
	            return mid;
	        }
	        else if(pow(mid,n)<=m){
	            low=mid+1;
	        }
	        else{
	            high=mid-1;
	        }
	    }
	    return -1;
	}  
};
