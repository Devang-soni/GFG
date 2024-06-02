/*
Given a list s that initially contains only a single value 0. There will be q queries of the following types:

0 x: Insert x in the list
1 x: For every element a in s, replace it with a ^ x. ('^' denotes the bitwise XOR operator)
Return the sorted list after performing the given q queries.
*/

class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        vector<int> ans;
        int x = 0;
        for(int i=0;i<q;i++){
            if(queries[i][0]==1)x = x^queries[i][1];
        }
        
        ans.push_back(0^x);
        for(int i=0;i<q;i++){
            if(queries[i][0]==0){
                ans.push_back(queries[i][1]^x);
            }else{
                x = x^queries[i][1];
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
