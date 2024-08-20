/*
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Examples : 

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5
*/

class Solution {
  public:
    
    int minTime(Node*r, int target) 
    {
      // Your code goes here
      int ans = 0;
        
      function<pair<bool,int>(Node*)>get_time=[&](Node* root){
        pair<bool,int>temp;
        
        if(!root){
          temp.first=false;
          temp.second=0;
          return temp;    
        }
        
        pair<bool,int>left = get_time(root->left), right = get_time(root->right);
        if(!left.first && !right.first){
            ans = max(ans,max(left.second, right.second));
            int val = max(left.second, right.second);
            if(root->data == target){
                temp.first=true;
                temp.second=1;
                return temp;
            }
            
            temp.first=false;
            temp.second=1+val;
            return temp;
        }
        else{
            ans = max(ans, left.second + right.second);
            temp.first=true;
            temp.second=1;
            
            if(left.first){
                temp.second+=left.second;
                return temp;
            }
            
            else{
                temp.second+=right.second;
                return temp;
            }
        }
      };
        
      get_time(r);
      return ans;
    }
};

