/*
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the kth position of the final sorted array.
 

Example 1:

Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.
Example 2:
Input:
arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
Output:
256
Explanation:
Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.
*/

class Solution {
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        int i = 0, j = 0, current = INT_MIN, m1 = 0;
        
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                current = arr1[i];
                i++;
            } else {
                current = arr2[j];
                j++;
            }
            
            m1++;
            if (m1 == k) {
                return current;
            }
        }
        
     
        while (i < n) {
            current = arr1[i];
            m1++;
            if (m1 == k) {
                return current;
            }
            i++;
        }
        
     
        while (j < m) {
            current = arr2[j];
            m1++;
            if (m1 == k) {
                return current;
            }
            j++;
        }
        
        return -1;
    }
};
