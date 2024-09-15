/*
Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes will be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as the order of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Note: h is the tree's height, and this space is used implicitly for the recursion stack.

TreeToList

Examples:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3

Explanation: DLL would be 3<=>1<=>2
Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40

Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.
*/


class Solution {
  public:
   void inorder(Node *root,Node *&head){
      if(root==NULL) return ;
      
      inorder(root->left,head);
      Node *curr=new Node(root->data);
      head->right=curr;
      curr->left=head;
      head=curr;
      inorder(root->right,head);
  }
    Node* bToDLL(Node* root) {
        Node *head=new Node(-1);
        Node *head1=head;
        inorder(root,head);
        // head->right=head1->right;
        // head1->right->left=head;
        Node *temp=head1->right;
        if(temp!=NULL) temp->left=NULL;
        delete(head1);
        // // head->right=head1;
        // head1->left=head;
        return temp;
    }


};
