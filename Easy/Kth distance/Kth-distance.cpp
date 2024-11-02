/*
Given an unsorted array arr and a number k which is smaller than size of the array. Find if the array contains duplicates within k distance.

Examples:

Input: arr[] = [1, 2, 3, 4, 1, 2, 3, 4] and k = 3
Output: false
Explanation: All duplicates are more than k distance away.
Input: arr[] = [1, 2, 3, 1, 4, 5] and k = 3
Output: true
Explanation: 1 is repeated at distance 3.
*/

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
       unordered_map<int,int> mp; 
       for(int i = 0; i < arr.size(); i++){
           int num = arr[i]; 
           if(mp.count(num)){
                int prevPos = mp[arr[i]]; 
                if(i - prevPos <= k) return true; 
           }
           mp[arr[i]] = i; 
       }
       return false; 
    }
};
