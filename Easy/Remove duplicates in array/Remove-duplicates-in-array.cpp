/*
Given an array arr consisting of positive integer numbers, remove all duplicate numbers.

Example:

Input: arr[] = [2, 2, 3, 3, 7, 5] 
Output: [2, 3, 7, 5]
Explanation: After removing the duplicates 2 and 3 we get 2 3 7 5.
Input: arr[] = [2, 2, 5, 5, 7, 7] 
Output: [2, 5, 7]
Input: arr[] = [8, 7] 
Output: [8, 7]

*/
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        unordered_map<int, int> umap;
        vector<int> ans;
        for(auto x : arr) {
            if(umap.count(x) == 0) {
                ans.push_back(x);
                umap[x]++;
            }
        }
        return ans;
    }
};
