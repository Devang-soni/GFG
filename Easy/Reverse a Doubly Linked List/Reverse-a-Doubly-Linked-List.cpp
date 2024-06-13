/*
Given a doubly linked list of n elements. Your task is to reverse the doubly linked list in-place.

Example 1:

Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
Example 2:

Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75

*/

class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
      Node *last=NULL;
      Node *temp=head;
      if(temp==NULL||temp->next==NULL)
      return head;
      while(temp){
          last=temp->prev;
          temp->prev=temp->next;
          temp->next=last;
          temp=temp->prev;
      }
      return last->prev;
    }
};
