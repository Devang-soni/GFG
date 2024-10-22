/*

Given an array arr[] and two integers say, x and y, find the number of sub-arrays in which the number of occurrences of x is equal to the number of occurrences of y.

Examples:

Input: arr[] = [1, 2, 1] , x= 1 , y = 2
Output: 2
Explanation: The possible sub-arrays have same equal number of occurrences of x and y are:
1) [1, 2], x and y have same occurrence(1).
2) [2, 1], x and y have same occurrence(1).
Input: arr[] = [1, 2, 1] , x = 4 , y = 6
Output: 6
Explanation: The possible sub-arrays have same equal number of occurrences of x and y are:
1) [1], x and y have same occurrence(0).
2) [2], x and y have same occurrence(0).
3) [1], x and y have same occurrence(0).
4) [1, 2], x and y have same occurrence(0).
5) [2, 1], x and y have same occurrence(0).
6) [1, 2, 1], x and y have same occurrence(0).
Input: arr[] = [1, 2, 1] , x= 1 , y = 4
Output: 1
Explanation: The possible sub-array have same equal number of occurrences of x and y is: [2], x and y have same occurrence(0)

*/

class Solution {
public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        int cnt = 0, diff = 0;
        map<int, int> mp; 
        mp[0] = 1; 
        for (int i = 0; i < (int)arr.size(); i++) {
            if (arr[i] == x) {
                diff++;
            } else if (arr[i] == y) {
                diff--;
            }
            cnt += mp[diff];
            mp[diff]++;
        }
        return cnt;
    }
};
