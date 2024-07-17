/*
Given a strictly increasing sorted rotated array arr. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]

Examples:

Input: arr = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is 5 1 2 3 4. The original sorted array is 1 2 3 4 5. We can see that the array was rotated 1 times to the right.
Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated.
*/

class Solution {
  public:
    int minimum(vector<int> &arr)
    {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==arr[low]&&arr[mid]==arr[high])
            {
                ans=min(ans,arr[low]);
                low++;
                high--;
                continue;
            }
            if(arr[mid]>=arr[low])
            {
                ans=min(ans,arr[low]);
                low=mid+1;
            }
            else
            {
                ans=min(ans,arr[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
    int findKRotation(vector<int> &arr) {
        
        for(int i=0;i<arr.size();i++)
        {
            if(minimum(arr)==arr[i])
            return i;
        }
        return -1;
        
    }
};


