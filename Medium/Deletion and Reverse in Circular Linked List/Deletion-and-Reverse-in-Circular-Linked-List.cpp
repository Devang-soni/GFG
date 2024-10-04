/*
Given a Circular Linked List. The task is to delete the given node, key in the circular linked list, and reverse the circular linked list.

Note:

You don't have to print anything, just return the head of the modified list in each function.
Nodes may consist of Duplicate values.
The key may or may not be present.
Examples:

Input: Linked List: 2->5->7->8->10, key = 8

Output: 10->7->5->2 
Explanation: After deleting 8 from the given circular linked list, it has elements as 2, 5, 7, 10. Now, reversing this list will result in 10, 7, 5, 2 & the resultant list is also circular.
Input: Linked List: 1->7->8->10, key = 8

Output: 10->7->1
Explanation: After deleting 8 from the given circular linked list, it has elements as 1, 7,10. Now, reversing this list will result in 10, 7, 1 & the resultant list is also circular.
Input: Linked List: 3->6->4->10, key = 9
Output: 10->4->6->3
Explanation: As there no key present in the list, so simply reverse the list & the resultant list is also circular.

*/

class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        Node* curr= head->next;
        Node* prev = head;
        Node* nxt = NULL;
        while(curr != head){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr= nxt;
        }
        head->next = prev;
        return prev;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        Node* temp = head->next;
        Node* prev = head;
        if(head->data == key){
            while(temp!= head){
                prev = temp;
                temp = temp->next;
            }
        }
        else{
            while(temp != head and temp->data != key){
                prev = temp;
                temp = temp->next;
            }
        }
        if(head->data == key or temp != head)
        prev->next = temp->next;
        return head->data==key?prev->next:head;
    }
};

