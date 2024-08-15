/*
Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.



Examples:

Note: 'c' is the position of the node to which the last node is connected. If c is 0, then there is no loop.

Input: LinkedList: 25->14->19->33->10->21->39->90->58->45, c = 4
Output: 7
Explanation: The loop is 45->33. So length of loop is 33->10->21->39-> 90->58->45 = 7. The number 33 is connected to the last node to form the loop because according to the input the 4th node from the beginning(1 basedindex) will be connected to the last node for the loop.
 
Input: LinkedList: 1->0, c = 2
Output: 0
Explanation: The length of the loop is 2.

Input: LinkedList: 5->4, c = 0
Output: 0
Explanation: There is no loop.
*/

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    
    int findLength(Node *slow, Node *fast){
        int count =1;
        fast = fast->next;
        while(slow != fast ){
            count++;
            fast = fast->next;
        }
        return count;
    }
    
    int countNodesinLoop(struct Node *head) {
        // Code here
        
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                return findLength(slow, fast);
            }
            
        }
        return 0;
        
    }
};
