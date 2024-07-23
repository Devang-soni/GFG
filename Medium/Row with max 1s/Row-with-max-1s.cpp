/*
Given a boolean 2D array, consisting of only 1's and 0's, where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's. Return the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

Examples :

Input: arr[][] = [[0, 1, 1, 1],[0, 0, 1, 1],[1, 1, 1, 1],[0, 0, 0, 0]]
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).
Input: arr[][] = [[0, 0], [1, 1]]
Output: 1
Explanation: Row 1 contains 2 1's (0-based indexing).
*/

class Solution {
  public:
    int lowerbound(vector<int> arrs  , int x){
        int n = arrs.size();
        int low =0 ; 
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low + high)/2;
            if(arrs[mid] >=x){
                ans = mid ;
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return ans ;
        
    }
    int rowWithMax1s(vector<vector<int> > arr) {
        int cnt = 0;
        int index =-1;
        
        int n = arr.size();
        int m = arr[0].size();
        for(int i=0;i<n;i++){
            int cnt_one = m- lowerbound(arr[i] , 1);
            if(cnt_one > cnt){
                cnt = cnt_one;
                index =i;
            }
        }
        return index;
        
    }
};

