/*
Given a linked list with string data, check whether the combined string formed is palindrome. If the combined string is palindrome then return true otherwise return false.

Example:

Input:

Output : true
Explanation: As string "abcddcba" is palindrome the function should return true.
Input:

Output : false
Explanation: As string "abcdba" is not palindrome the function should return false.
*/

class Solution {
public:
    bool compute(Node* head) {
        // Your code goes here
          string s="";
        Node* temp=head;
        while(temp!=NULL)
        {
            s+=temp->data;
            temp=temp->next;
        }
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
};

