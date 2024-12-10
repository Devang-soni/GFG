/*
Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Examples:

Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
Output: 1
Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.
Input: intervals[][] = [[1, 3], [1, 3], [1, 3]]
Output: 2
Explanation: You need to remove two [1, 3] to make the rest of the intervals non-overlapping.
Input: intervals[][] = [[1, 2], [5, 10], [18, 35], [40, 45]]
Output: 0
Explanation: All ranges are already non overlapping.
*/

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        
          sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1] < b[1];
        });
        int count = 0;
        int last = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            
            if(last > intervals[i][0]){
               count++;
            }
            else{
                last = intervals[i][1];
            }
        }
        return count;
    }
};
