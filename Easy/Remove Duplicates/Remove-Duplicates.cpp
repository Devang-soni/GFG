/*
Given a string str without spaces, the task is to remove all duplicate characters from it, keeping only the first occurrence.

Note: The original order of characters must be kept the same. 

Examples :

Input: str = "zvvo"
Output: "zvo"
Explanation: Only keep the first occurrence
Input: str = "gfg"
Output: "gf"
Explanation: Only keep the first occurrence
*/

class Solution{
public:	
		
	string removeDups(string S) 
	{
	    // Your code goes here
	    map<int,int>m;
	    string str="";
	    for(int i=0;i<S.length();i++)
	    {
	        m[S[i]]++;
	    
	    if(m[S[i]]==1)
	      str=str+S[i];
	    }
	    return str;
	}
	
};
