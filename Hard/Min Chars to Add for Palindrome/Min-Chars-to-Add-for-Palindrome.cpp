/*
Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.

Examples:

Input: s = "abc"
Output: 2
Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"
Input: s = "aacecaaaa"
Output: 2
Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"

*/
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
            string rev_s = s;
            reverse(rev_s.begin(), rev_s.end());
            string concat = s + '#' + rev_s;
            int n = concat.size();
            vector<int> lps(n, 0);
            for (int i = 1; i < n; i++) {
                int len = lps[i - 1];
                while (len > 0 && concat[i] != concat[len]) len = lps[len - 1];
                if (concat[i] == concat[len]) len++;
                lps[i] = len;
            }
            return s.size() - lps.back();
    }
    
};
