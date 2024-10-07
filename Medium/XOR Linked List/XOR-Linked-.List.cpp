/*
An ordinary Doubly Linked List requires space for two address fields to store the addresses of previous and next nodes. A memory-efficient version of the Doubly Linked List can be created using only one space for the address field with every node. This memory-efficient Doubly Linked List is called XOR Linked List or Memory Efficient as the list uses bit-wise XOR operation to save space for one address.

Given a stream of data of size N for the linked list, your task is to complete the function insert() and getList(). The insert() function pushes (or inserts at the beginning) the given data in the linked list and the getList()  function returns the linked list as a list.

Note:

A utility function XOR() takes two Node pointers to get the bit-wise XOR of the two Node pointers. Use this function to get the XOR of the two pointers.
The driver code prints the returned list twice, once forward and once backwards.
Examples:

Input:
LinkedList: 9<->5<->4<->7<->3<->10

Output:
10 3 7 4 5 9
9 5 4 7 3 10
Input:
LinkedList: 58<->96<->31

Output:
31 96 58
58 96 31

*/


struct Node *insert(struct Node *head, int data) {
    // Code here
    struct Node *newHead = new Node( data );
    newHead->npx = XOR( NULL, head );
    if( head )
        head->npx = XOR( newHead, XOR( NULL, head->npx ) );
    return newHead;
}

vector<int> getList(struct Node *head) {
    // Code here
    struct Node *prev, *next;
    prev = NULL;
    vector<int> res;
    while( head ) {
        res.push_back( head->data );
        next = XOR( head->npx, prev );
        prev = head;
        head = next;
    }
    return res;
}
