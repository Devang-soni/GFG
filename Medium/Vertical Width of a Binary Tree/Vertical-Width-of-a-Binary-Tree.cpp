/*
Given a Binary Tree. You need to find and return the vertical width of the tree.

Examples :

Input:
         1
       /    \
      2      3
     / \    /  \
    4   5  6   7
            \   \
             8   9
Output: 6
Explanation: The width of a binary tree is
the number of vertical paths in that tree.



The above tree contains 6 vertical lines.
Input:
     1
    /  \
   2    3
Output: 3
Explanation: The above tree has 3 vertical lines, hence the answer is 3.
*/

class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int maxi = 0;
    int mini = 0;
    void Solve(Node* root, int distance)
    {
        if(root == NULL)
           return;
        maxi = max(maxi,distance);
        mini = min(mini,distance);
        
        Solve(root->left,distance-1);
        Solve(root->right, distance+1);
        
    }
    int verticalWidth(Node* root) {
        if(root == NULL)
          return 0;
          
       Solve(root,0);
       return (maxi-mini)+1;
    }
};



