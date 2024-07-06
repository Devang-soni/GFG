/*

Given a Binary Tree, complete the function to populate the next pointer for all nodes. The next pointer for every node should point to the Inorder successor of the node.
You do not have to return or print anything. Just make changes in the root node given to you.

Note: The node having no in-order successor will be pointed to -1. You don't have to add -1 explicitly, the driver code will take care of this.

Examples :

Input:
       10
       /  \
      8   12
     /
    3
Output: 3->8 8->10 10->12 12->-1
Explanation: The inorder of the above tree is : 3 8 10 12. So the next pointer of node 3 is pointing to 8 , next pointer of 8 is pointing to 10 and so on.And next pointer of 12 is pointing to -1 as there is no inorder successor of 12.
Input:
       1
      /  
     2 
   /
 3  
Output: 3->2 2->1 1->-1
Explanation: The inorder of the above tree is: 3 2 1. So the next pointer of node 3 is pointing to 2 , next pointer of 2 is pointing to 1. And next pointer of 1 is pointing to -1 as there is no inorder successor of 1.

*/



/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
    // Node* prev=NULL;
    // void inorder(Node* root,vector<int> &in,unordered_map<int,Node*> &mp){
    //     if(root==NULL){
    //         return;
    //     }
    //     inorder(root->left,in,mp);
    //     mp[root->data]=root;
    //     in.push_back(root->data);
    //     inorder(root->right,in,mp);
        
    // }
    
    // void solve(Node* root,int &index,vector<int>& in,unordered_map<int,Node*> &mp){
    //     if(root==NULL){
    //         return;
    //     }
        
    //     solve(root->left,index,in,mp);
    //     if(index<in.size()-1){
    //         int element=in[index];
    //         root->next=mp[in[index+1]];
    //     }
        
    //     index++;
    //     solve(root->right,index,in,mp);
    // }

    void solve(Node* root,Node* &prev){
        if(root==NULL){
            return;
        }
        
        solve(root->left,prev);
        if(prev==NULL){
            prev=root;
        }else{
            prev->next=root;
            prev=root;
        }
        solve(root->right,prev);
    }

    void populateNext(Node *root) {
        Node* prev=NULL;
        solve(root,prev);
        
        // vector<int> in;
        // unordered_map<int,Node*> mp;
        // inorder(root,in,mp);
        // int index=0;
        // solve(root,index,in,mp);
    }
    
    
};
