/*
You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.

Example1:

Input: 
2<->2<->10<->8<->4<->2<->5<->2
2
Output: 
10<->8<->4<->5
Explanation: 
All Occurences of 2 have been deleted.

Example2:

Input: 
9<->1<->3<->4<->5<->1<->8<->4
9
Output: 
1<->3<->4<->5<->1<->8<->4
Explanation: 
All Occurences of 9 have been deleted.
*/

class Solution {
public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp = *head_ref;
        
        while (temp != NULL) {
            if (temp->data == x) {
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;


                if (nextNode != NULL) {
                    nextNode->prev = prevNode;
                }
                if (prevNode != NULL) {
                    prevNode->next = nextNode;
                } else {
                    *head_ref = nextNode;
                }
                delete temp;
                temp = nextNode;
            } else {
                temp = temp->next;
            }
        }
    }
};

