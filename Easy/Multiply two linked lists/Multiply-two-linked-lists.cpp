/*
Given elements as nodes of the two singly linked lists. The task is to multiply these two linked lists, say L1 and L2.

Note: The output could be large take modulo 10^9+7.

Examples :

Input: LinkedList L1 : 3->2 , LinkedList L2 : 2
Output: 64
Explanation: 

Multiplication of 32 and 2 gives 64.
Input: LinkedList L1: 1->0->0 , LinkedList L2 : 1->0
Output: 1000
Explanation: 

Multiplication of 100 and 10 gives 1000.
*/

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        
        long long num1 =0;
        long long num2 = 0;
        int mod = 1000000007;
        
        Node *temp = first;
        while(temp){
            num1 = (num1 *10 + (temp->data)) %mod;
            temp = temp->next;
        }
        
        temp = second;
        while(temp){
            num2 = (num2 *10 + (temp->data)) %mod;
            temp = temp->next;
        }
        
        
        return (num1 * num2) % mod;
    }
};
