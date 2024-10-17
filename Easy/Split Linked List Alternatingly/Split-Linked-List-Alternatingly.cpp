/*
Given a singly linked list's head. Your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller lists. The sublists should be made from alternating elements from the original list.
Note: 

The sublist should be in the order with respect to the original list.
Your have to return an array containing the both sub-linked lists.
Examples:

Input: LinkedList = 0->1->0->1->0->1
Output: 0->0->0 , 1->1->1
Explanation: After forming two sublists of the given list as required, we have two lists as: 0->0->0 and 1->1->1.

Input: LinkedList = 2->5->8->9->6
Output: 2->8->6 , 5->9
Explanation: After forming two sublists of the given list as required, we have two lists as: 2->8->6 and 5->9.
Input: LinkedList: 7 
Output: 7 , <empty linked list>

*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
      if (!head) return {};
    
    
    Node* h1 = head;      
    Node* t1 = head; 
    
    Node* h2 = head->next;
    Node* t2 = head->next; 
    
 
    if (!h2) return {h1}; 
    
   
    while (t1 && t2) {
        if (t1->next) {
            t1->next = t1->next->next;  
            t1 = t1->next;             
        }
        if (t2->next) {
            t2->next = t2->next->next; 
            t2 = t2->next ;
        }
    }
    
    
    if (t1) t1->next = nullptr;
    if (t2) t2->next = nullptr;
    
    return {h1, h2};          
    }
};
