/*
Given an unsorted array Arr[] of N integers and an integer X, find floor and ceiling of X in Arr[0..N-1].
Floor of X is the largest element which is smaller than or equal to X. Floor of X doesn’t exist if X is smaller than smallest element of Arr[].
Ceil of X is the smallest element which is greater than or equal to X. Ceil of X doesn’t exist if X is greater than greatest element of Arr[].

Example 1:

Input:
N = 8, X = 7
Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
Output: 6 8
Explanation:
Floor of 7 is 6 and ceil of 7 
is 8.
Example 2:

Input:
N = 8, X = 10
Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
Output: 9 -1
Explanation:
Floor of 10 is 9 but ceil of 10 is not 
possible.
*/

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int left=0, right=n-1;
    int flor=-1, cel=-1;
    sort(arr, arr+n);
    while (left<=right){
        int mid = (right+left)/2;
        if (arr[mid]==x){
            return make_pair(arr[mid], arr[mid]);
        }
        else if (arr[mid]>x){
            right=mid-1;
            cel=arr[mid];
        }
        else{
            left=mid+1;
            flor=arr[mid];
        }
    }
    return make_pair(flor, cel);
}

