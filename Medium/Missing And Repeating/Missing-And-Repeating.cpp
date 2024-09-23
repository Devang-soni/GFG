/*
Given an unsorted array arr of of positive integers. One number 'A' from set {1, 2,....,n} is missing and one number 'B' occurs twice in array. Find numbers A and B.

Examples

Input: arr[] = [2, 2]
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.

*/

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        vector<int> ans;
        unordered_map<int, int> mp;
        int n= arr.size();
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
            
        }
        for(auto i:mp){
            if(i.second == 2) ans.push_back(i.first);
        }
        for(int i=1; i<=n; i++){
            if(mp.find(i) == mp.end())  ans.push_back(i);
        }
        
        return ans;
    }
};
