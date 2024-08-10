/*
You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
Input: LinkedList: 1->2->3
Output: 124
 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
*/


class Solution {
  public:
  
  Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
  
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        
        head = reverse(head);
        Node* temp = head;
        int carry = 1;
        
        while(temp != NULL){
            temp->data = temp->data + carry;
            
            if(temp->data <10){
                carry = 0;
                break;
            }
            else{
                temp->data = 0;
                carry = 1;
            }
            
            temp = temp->next;
        }
        
        if(carry == 1){
            Node* newNode = new Node(1);
            head = reverse(head);
            newNode->next = head;
            
            return newNode;
        }
        head = reverse(head);
        return head;
        
    }
};
