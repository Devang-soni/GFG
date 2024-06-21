/*
You are given a string str containing two fractions a/b and c/d, compare them and return the greater. If they are equal, then return "equal".

Note: The string str contains "a/b, c/d"(fractions are separated by comma(,) & space( )). 

Examples

Input: str = "5/6, 11/45"
Output: 5/6
Explanation: 5/6=0.8333 and 11/45=0.2444, So 5/6 is greater fraction.
Input: str = "8/1, 8/1"
Output: equal
Explanation: We can see that both the fractions are same, so we'll return a string "equal".
*/

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
          int a, b, c, d;
        char slash1, slash2, comma;
        stringstream ss(str);
        
        ss >> a >> slash1 >> b >> comma >> c >> slash2 >> d;

        // Compare the fractions using cross multiplication
        int lhs = a * d;
        int rhs = b * c;
        
        if (lhs > rhs) {
            return to_string(a) + "/" + to_string(b);
        } else if (lhs < rhs) {
            return to_string(c) + "/" + to_string(d);
        } else {
            return "equal";
        }
    }
};

