/*
Given a binary tree, your task is to find all duplicate subtrees from the given binary tree.

Duplicate Subtree : Two trees are duplicates if they have the same structure with the same node values.

Note:  Return the root of each tree in the form of a list array & the driver code will print the tree in pre-order tree traversal in lexicographically increasing order.

Examples:

Input : 
 
Output: 2 4   
        4
Explanation: The above tree have two duplicate subtrees.i.e 
  2
 /
4  and 4. Therefore, you need to return the above tree root in the form of a list.
Input:     5
          / \
         4   6
        / \
       3   4
          / \
         3   6
Output: 
3
6
Explanation: In the above tree, there are two duplicate subtrees.i.e
3 and 6. Therefore, you need to return the above subtrees root in the form of a list.
*/

class Solution {
  public:
    unordered_map<string,int> mpp;
    vector<Node*> ans;
    vector<Node*> printAllDups(Node* root) {
        dfs(root);
        return ans;
    }
    string dfs(Node* root) {
        if (root == nullptr) {
            return "#";
        }
        string s = to_string(root->data) + "," + dfs(root->left) + "," + dfs(root->right);
        if (mpp[s] == 1) {
            ans.push_back(root);
        }
        mpp[s]++;
        return s;
    }
};


