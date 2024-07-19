/*
Given an array arr containing non-negative integers. Count and return an array ans where ans[i] denotes the number of smaller elements on right side of arr[i].

Examples:

Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
Output: [6, 1, 1, 1, 0, 1, 0]
Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.
Input: arr[] = [1, 2, 3, 4, 5]
Output: [0, 0, 0, 0, 0]
Explanation: There are 0 smaller elements right after 1. There are 0 smaller elements right after 2. And so on.
*/

class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        vector <int> ans;
        vector <int> temp = arr;
        
        sort(temp.begin(),temp.end());
        
        for(int i=0;i<n;i++){
            int index = lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            ans.push_back(index);
            temp.erase(temp.begin()+index);
        }
        return ans;
    }
};
