/*
Given head of a linked list, the task is to find the middle. For example, the middle of 1-> 2->3->4->5 is 3. If there are two middle nodes (even count), return the second middle. For example, middle of 1->2->3->4->5->6 is 4.

The following is internal representation of every test case (two inputs).
n : Size of the linked list
value[] :  An array of values that represents values of nodes.

Examples:

Input: n = 4, value[] = {1,2,3,4,5}
Output: 3 
Explanation: The given linked list is 1->2->3->4->5 and its middle is 3.
Input: n = 6, value[] = {2,4,6,7,5,1}
Output: 7 
Explanation: The given linked list is 2->4->6->7->5->1 and its middle is 7.
*/

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        if(head ==NULL){
            return -1;
        }
        
        Node *slow = head;
        Node *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
        }
        return slow->data;
    }
};
