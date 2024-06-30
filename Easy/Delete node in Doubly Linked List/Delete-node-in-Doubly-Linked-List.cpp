/*
Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

Examples:

Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 3  

After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
 
Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output: 5 2 9

*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(x==1){
          return head->next;
        }
        Node* temp = head;
        for(int i = 1;i<x-1;i++){
            temp = temp->next;
        }
         temp->next = temp->next->next;
         if(temp->next!=nullptr){
             temp->next->prev = temp;
         }
        return head;
    }
};
