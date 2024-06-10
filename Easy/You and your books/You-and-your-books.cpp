/*
You have n stacks of books. Each stack of books has some height arr[i] equal to the number of books on that stack ( considering all the books are identical and each book has a height of 1 unit ). In one move, you can select any number of consecutive stacks of books such that the height of each selected stack of books arr[i] <= k. Once such a sequence of stacks is chosen, You can collect any number of books from the chosen sequence of stacks.
What is the maximum number of books that you can collect this way?

Example 1

Input
8 1
3 2 2 3 1 1 1 3
Output
3
Explanation 
We can collect maximum books from consecutive stacks numbered 5, 6, and 7 having height less than equal to K.
Example 2

Input
8 2
3 2 2 3 1 1 1 3
Output
4
Explanation
We can collect maximum books from consecutive stacks numbered 2 and 3 having height less than equal to K.
*/

class Solution {
  public:
    long long max_Books(int a[], int n, int k) {
        long long ans = 0;
        int count = 0;
        long long fin = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= k)
                ans += a[i];
            else
                ans = 0;

            fin = max(fin, ans);
        }
        return fin;
    }
};
