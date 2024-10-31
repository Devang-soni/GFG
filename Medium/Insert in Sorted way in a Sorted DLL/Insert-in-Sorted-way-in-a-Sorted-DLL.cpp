/*
Given a sorted doubly linked list and an element x, you need to insert the element x into the correct position in the sorted Doubly linked list(DLL).

Note: The DLL is sorted in ascending order

Example:

Input: LinkedList: 3->5->8->10->12 , x = 9

Output: 3->5->8->9->10->12

Explanation: Here node 9 is inserted in the Doubly Linked-List.
Input: LinkedList: 1->4->10->11 , x = 15

Output: 1->4->10->11->15

*/

class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        struct Node*newnode=getNode(x);
        
        if(x<=head->data){
            newnode->next=head;
            head=newnode;
            return head;
        }
        
        Node*prev=head;
        Node*curr=head->next;
        
        while(curr){
           if(prev->data<x && x<=curr->data){
               newnode->next=curr;
               prev->next=newnode;
               break;
           }
           
           prev=prev->next;
           curr=curr->next;
        }
        
        if(!curr)
          prev->next=newnode;
        
        return head;

    }
};
