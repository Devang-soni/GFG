/*
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 

Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
*/

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int ans=0;
    int diameter(Node* root) {
        height(root);
        return ans;
    }
    
    int height(Node* root)
    {
        if(!root)   return 0;
        int h1=height(root->left);
        int h2=height(root->right);
        ans=max(ans,1+h1+h2);
        return 1+max(h1,h2);
    }
};

