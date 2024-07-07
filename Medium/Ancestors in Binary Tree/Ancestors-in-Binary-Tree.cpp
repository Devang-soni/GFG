/*
Given a Binary Tree and an integer target. Find all the ancestors of the given target.

Note:

The ancestor of node x is node y, which is at the upper level of node x, and x is directly connected with node y. Consider multiple levels of ancestors to solve this problem.
In case there are no ancestors available, return an empty list.
Examples:

Input:
         1
       /   \
      2     3
    /  \    /  \
   4   5  6   8
  /
 7
target = 7
Output: [4 2 1]
Explanation: The given target is 7, if we go above the level of node 7, then we find 4, 2 and 1. Hence the ancestors of node 7 are 4 2 and 1
Input:
        1
      /   \
     2     3
target = 1
Output: [ ]
Explanation: Since 1 is the root node, there would be no ancestors. Hence we return an empty list.
*/


class Solution {
  public:
    // Function should return all the ancestor of the target node
    bool anscestor(struct Node *root,int target,vector<int> &ans){
        //base case
        if(root == NULL){
            return false;
        }
        if(root-> data== target){
            return true;
        }
        //recursive case
        if(anscestor(root->left , target, ans) || anscestor(root->right , target, ans)){
            ans.push_back(root->data);
            return true;
        }
        return false;
    }
    vector<int> Ancestors(struct Node *root, int target) {
        // CodeGenius
        vector<int> ans;
        anscestor(root,target,ans);
        return ans;
    }
};
