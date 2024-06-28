/*
Given the two singly Linked Lists respectively. The task is to check whether two linked lists are identical or not. 
Two Linked Lists are identical when they have the same data and with the same arrangement too. If both Linked Lists are identical then return true otherwise return false. 

Examples:

Input:
LinkedList1: 1->2->3->4->5->6
LinkedList2: 99->59->42->20
Output: false
Explanation:

As shown in figure linkedlists are not identical.
Input:
LinkedList1: 1->2->3->4->5
LinkedList2: 1->2->3->4->5
Output: true
Explanation: 
 
As shown in figure both are identical.
*/

bool areIdentical(struct Node *head1, struct Node *head2) {
    // Code here
    Node*temp1=head1;
    Node*temp2=head2;
    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
        {
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    
    if(temp1==NULL&&temp2==NULL) return true;
    return false;
}
