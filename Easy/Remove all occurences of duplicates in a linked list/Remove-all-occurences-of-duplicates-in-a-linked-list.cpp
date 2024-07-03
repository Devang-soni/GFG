/*
Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list. 

Examples:

Input: Linked List = 23->28->28->35->49->49->53->53
Output: 23 35
Explanation: The duplicate numbers are 28, 49 and 53 which are removed from the list.
Input: Linked List = 11->11->11->11->75->75
Output: Empty list
Explanation: All the nodes in the linked list have duplicates. Hence the resultant list would be empty.
*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        
        if(!head || !head->next) return head;//if there is only one condition then head will be printed
        
        Node *prev = NULL;
        Node *curr = head;
        Node *nextnode;
        
        while(curr){
        nextnode=curr->next;
            bool flag=false;
            while(nextnode && curr->data==nextnode->data){
                flag=true;
                Node* del=nextnode;
                nextnode=nextnode->next;
                delete del;
            }
            if(flag){
                if(prev!=NULL){
                    prev->next=nextnode;
                }
                else{
                    head=nextnode;
                }
                delete curr;
            }
            else{
                prev=curr;
            }
            curr=nextnode;
        }
        return head;
        
        /*while(prev != NULL && curr != NULL){
            prev->next = curr->next;
            delete prev;
            delete curr;
            
        }
        //temp= temp->next;
        
        prev = prev->next;
            if(prev != NULL){
                curr = prev->next;
            }
        */
    }
};

