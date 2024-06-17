/*
Given the coordinates of the endpoints(p1,q1, and p2,q2) of the two line segments. Check if they intersect or not. If the Line intersects return true otherwise return false.

Examples

Input: p1=(1,1), q1=(10,1), p2=(1,2), q2=(10,2)
Output: false
Explanation:The two line segments formed by p1-q1 and p2-q2 do not intersect.
Input: p1=(10,0), q1=(0,10), p2=(0,0), q2=(10,10)
Output: true
Explanation: The two line segments formed by p1-q1 and p2-q2 intersect.
*/

class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        if ((f(p1,q1,p2) * f(p1,q1,q2) <= 0) && (f(p2,q2,p1) * f(p2,q2,q1) <= 0)) return "true";
        return "false";
    }
    
    double f(int l1[],int l2[],int p[]){
        return ((long)p[1] - l1[1])*((long)l2[0]-l1[0]) - ((long)p[0]-l1[0])*((long)l2[1]-l1[1]);
    }
};
