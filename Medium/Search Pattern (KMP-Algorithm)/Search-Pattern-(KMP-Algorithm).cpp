/*
Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
Note: Return an empty list in case of no occurrences of pattern.

Examples :

Input: txt = "abcab", pat = "ab"
Output: [0, 3]
Explanation: The string "ab" occurs twice in txt, one starts at index 0 and the other at index 3. 
Input: txt = "abesdu", pat = "edu"
Output: []
Explanation: There's no substring "edu" present in txt.
Input: txt = "aabaacaadaabaaba", pat = "aaba"
Output: [0, 9, 12]
*/

class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        int n=txt.size();
        int m=pat.size();
        vector<int>ans;
        int j=0;
        for(int i=0;i<n-m+1;i++)
        {
            if(txt[i]!=pat[0])
            {
                continue;
            }
            string temp=txt.substr(i,m);
            if(temp==pat)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
