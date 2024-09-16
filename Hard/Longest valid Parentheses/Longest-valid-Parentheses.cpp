/*
Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
Opening parenthesis must be closed in the correct order.
Examples :

Input: str = ((()
Output: 2
Explaination: The longest valid parenthesis substring is "()".
Input: str = )()())
Output: 4
Explaination: The longest valid parenthesis substring is "()()".

*/

class Solution {
  public:
    int maxLength(string& str) {
        // code here
           stack<int> st;
        st.push(-1);
        int len = 0;
        int maxLen = 0;

        for(int i = 0; i< str.size(); i++){
            char ch = str[i];

            if(ch == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }
                else {
                    len = i - st.top();

                    maxLen = max(len, maxLen);
                }
            }
        }

        return maxLen;
    }
};

