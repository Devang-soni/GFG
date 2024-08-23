/*
Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Examples :

Input:
   1
 /  \
3    2
Output: 1 3

Input:

Output: 10 20 40
*/

vector<int> leftView(Node *root)
{
   // Your code here
   
   vector<int> result;
   
   if(!root){
       return result;
   }
   
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       int size = q.size();
       result.push_back(q.front() -> data);
       
       while(size--){
           Node* t = q.front();
           q.pop();
           if(t->left) q.push(t->left);
           if(t->right) q.push(t->right);
       }
   }
   
   return result;
}
