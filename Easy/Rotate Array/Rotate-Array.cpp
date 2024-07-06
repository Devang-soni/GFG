/*
Given an unsorted array arr[] of size n. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. 

Examples :

Input: n = 5, d = 2 arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2
Explanation: 1 2 3 4 5  when rotated by 2 elements, it becomes 3 4 5 1 2.
Example 2:

Input: n = 10, d = 3 arr[] = {2,4,6,8,10,12,14,16,18,20}
Output: 8 10 12 14 16 18 20 2 4 6
Explanation: 2 4 6 8 10 12 14 16 18 20 when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.

*/

class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        
       d=d%n;
        int temp[d];
        
        for(int i =0 ;i<n;i++){
            
            if(i<d){
                temp[i]=arr[i];
            }
            else{
                arr[i-d]=arr[i];
            }
            
        }
        int j=0;
        for(int i =n-d;i<n;i++){
            arr[i] = temp[j];
            j++;
        }
    }
};

