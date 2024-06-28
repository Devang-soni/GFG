/*
Given a two-dimensional integer array arr of dimensions n x n, consisting solely of zeros and ones, identify the row or column (using 0-based indexing) where all elements form a palindrome. If multiple palindromes are identified, prioritize the palindromes found in rows over those in columns. Within rows or columns, the palindrome with the smaller index takes precedence. The result should be represented by the index followed by either 'R' or 'C', indicating whether the palindrome was located in a row or column. The output should be space-separated. If no palindrome is found, return the string -1.

Examples:

Input: 
arr[][] =  [[1, 0, 0], 
           [0, 1, 0],
           [1, 1, 0]]
Output: 1 R
Explanation: In the first test case, 0-1-0 is a palindrome 
occuring in a row having index 1.
Input: 
arr[][] =   [[1, 0],
           [1, 0]]
Output: 0 C
Explanation: 1-1 occurs before 0-0 in the 0th column. And there is no palindrome in the two rows.
*/

class Solution {
 private:
    bool isPalindrome(vector<int>& v){
        int n = v.size();
        int i=0;
        int j = n-1;
        
        while(i<j){
            if(v[i]!=v[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
  public:
    string pattern(vector<vector<int>> &arr) {
        int rows = arr.size();
        int cols = arr[0].size();
        
        //check all rows
        for(int i=0;i<rows;i++){
            if(isPalindrome(arr[i])){
                return to_string(i) + " R";
            }
        }
        
        //check cols
        for(int i=0;i<cols;i++){
            int lo=0;
            int hi = rows-1;
            bool flag = true;
            while(lo < hi){
                if(arr[lo][i]!=arr[hi][i]) {
                    flag = false;
                    break;
                }
                lo ++;
                hi--;
            }
            if(flag){
                return to_string(i) + " C";
            }
        }
        
        
        return "-1";
    }
};
