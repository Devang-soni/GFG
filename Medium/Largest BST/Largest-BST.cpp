/*
Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
Note: Here Size equals the number of nodes in the subtree.

Examples :

Input:   1
        /  \
        4   4              
       / \ 
      6   8
Output: 1 
Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

Input:    6
        /   \
      6      2              
       \    / \
        2  1   3
Output: 3
Explanation: The following sub-tree is a BST of size 3:  2
                                                       /   \
                                                      1     3
*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
     int ans = 0;
    vector<int> solve(Node* root) {
        vector<int> left {root->data, INT_MIN, 0};
        if (root->left) {
            left = solve(root->left);
        }
        vector<int> right {INT_MAX, root->data, 0};
        if (root->right) {
            right = solve(root->right);
        }
        
        if (root->data > left[1] && root->data < right[0]) {
            ans = max(ans, left[2]+right[2]+1);
            return {left[0], right[1], left[2]+right[2]+1};
        }
        return {INT_MIN, INT_MAX, 0};
    }
    
    int largestBst(Node *root)
    {
        if (!root) return 0;
    	solve(root);
    	
    	return ans;
    }
};
