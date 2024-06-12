/* 
Given a linked list of n nodes and a key , the task is to check if the key is present in the linked list or not.

Example:

Input:
n = 4
1->2->3->4
Key = 3
Output:
True
Explanation:
3 is present in Linked List, so the function returns true.
*/
class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int data) {
        // Code here
        Node *curr = head;
        while(curr != NULL){
        if(curr->data == data) {
            return true;
        }
        curr =curr->next;
    }
    return false;
    }
};
