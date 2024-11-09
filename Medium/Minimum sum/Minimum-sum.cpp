/*
Given an array arr[] such that each element is in the range [0 - 9], find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers. Return a string without leading zeroes.

Examples :

Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: 604
Explanation: The minimum sum is formed by numbers 358 and 246.
Input: arr[] = [5, 3, 0, 7, 4]
Output: 82
Explanation: The minimum sum is formed by numbers 35 and 047.
Input: arr[] = [9, 4]
Output: 13
Explanation: The minimum sum is formed by numbers 9 and 4.
*/

class Solution {
  public:
    string fun(string num1,string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string result;
    
        while (i >= 0 || j >= 0 || carry) {
            int digit1 = i >= 0 ? num1[i] - '0' : 0;
            int digit2 = j >= 0 ? num2[j] - '0' : 0;
    
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
    
            i--;
            j--;
        }
    
        reverse(result.begin(), result.end());
        return result;
    }
    string minSum(vector<int> &arr) {
        // code here
        string a="",b="";
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(i%2) b.push_back(arr[i]+'0');
            else a.push_back(arr[i]+'0');
        }
        string res=fun(a,b);
        while(!res.empty() && res[0]=='0') res.erase(res.begin());
        return res;
    }
};

