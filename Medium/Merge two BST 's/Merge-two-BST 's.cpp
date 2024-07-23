/*
Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
*/

class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    
    
    void inorder(Node* root, vector<int> &ans){
        if(root == NULL) return ;
        
        inorder(root->left , ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
        
        return;
    }
    
    
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        
        vector<int> arr1, arr2, ans;
        inorder(root1, arr1);
        inorder(root2, arr2);
        
        int i=0, j=0;
        
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i] <= arr2[j]){
                ans.push_back(arr1[i++]);
            }
            else{
                ans.push_back(arr2[j++]);
            }
            
        }
        while(i< arr1.size()){
            ans.push_back(arr1[i++]);
        }
        while(j<arr2.size()){
            ans.push_back(arr2[j++]);
        }
        return ans;
        
        
    }
};



