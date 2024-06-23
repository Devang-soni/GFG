/*
Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string. 

 Examples:

Input:  str = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in
the given string (aa(bdc))p(dee) are
assigned the numbers as: 1 2 2 1 3 3.
Input:  str = "(((()("
Output: 1 2 3 4 4 5
Explanation: The highlighted brackets in
the given string (((()( are assigned
the numbers as: 1 2 3 4 4 5
*/

class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        
        vector<int> ans;
        stack<int > st;
        
         int n = str.length();
         int count = 1;
        
        for(int i=0;i<n;i++){
            char a = str[i];
            if(a == '('){
                st.push(count);
                ans.push_back(count);
                count++;
            }
            else if(a == ')'){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};

