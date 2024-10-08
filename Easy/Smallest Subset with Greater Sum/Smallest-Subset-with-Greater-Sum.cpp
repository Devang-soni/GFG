/*
You are given an array Arr of size N containing non-negative integers. Your task is to choose the minimum number of elements such that their sum should be greater than the sum of the rest of the elements of the array.

Example 1:

Input:
N = 4 
Arr[] = {2, 17, 7, 3}
Output:
1
Explanation:
If we only select element 17, the sum of the
rest of the elements will be (2+3+7)=12.
So the answer will be 1.
Example 2:

Input:
N = 4
Arr = {20, 12, 18, 4}
Output:
2
Explanation:
If we select 12 and 18 from the array,
the sum will be (12+18) = 30 and the sum of
the rest of the elements will be (20+4) = 24.
So, the answer will be 2. We can also
select 20 and 18 as well.
*/

class Solution{
    public:
    int minSubset(vector<int> &arr,int n){
        sort(arr.begin(), arr.end(), greater<int>());
        
        long sumLeft = 0;
        long sumRight = 0;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            sumRight += arr[i];
        }
        
        for(int i=0; i<n; i++)
        {
            sumLeft += arr[i];
            sumRight -= arr[i];
            if(sumLeft <= sumRight)
            {
               count++;
            }
            else
                return count+1;
        }
    }
};

