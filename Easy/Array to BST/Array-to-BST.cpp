/*
Given a sorted array. Convert it into a Height Balanced Binary Search Tree (BST). Return the root of the BST.

Height-balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

Note: The driver code will check the BST, if it is a Height-balanced BST, the output will be true otherwise the output will be false.

Examples :

Input: nums = [1, 2, 3, 4]
Output: true
Explanation: The preorder traversal of the following BST formed is [2, 1, 3, 4]:
           2
         /   \
        1     3
               \
                4
Input: nums = [1, 2, 3, 4, 5, 6, 7]
Ouput: true
Explanation: The preorder traversal of the following BST formed is [4, 2, 1, 3, 6, 5, 7]:
        4
       / \
      2   6
     / \   / \
    1 3  5 7
*/


class Solution {
  public:
    Node* helper(vector<int>&nums,int low,int high)
    {
        if(low>high)return nullptr;
        if(low == high)
        {
            //cout<<"Leaf is "<<nums[low]<<" "<<low<<endl;
            Node* leaf =new Node(nums[low]);
            return leaf;
        }
        int mid =low +(high-low)/2;
        Node* node =new Node(nums[mid]);
        //cout<<"Nums root "<<nums[mid]<<" "<<mid<<endl;
        node->left =helper(nums,low,mid-1);
        node->right =helper(nums,mid+1,high);
        return node;
    }
    Node* sortedArrayToBST(vector<int>& nums) 
    {
       return helper(nums,0,nums.size()-1);
    }
};
