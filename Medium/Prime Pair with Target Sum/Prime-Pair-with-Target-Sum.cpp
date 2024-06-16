/*
Given a number n, find out if n can be expressed as a+b, where both a and b are prime numbers. If such a pair exists, return the values of a and b, otherwise return [-1,-1] as an array of size 2.
Note: If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, and a < c then  [a, b] is considered as our answer.

Examples

Input: n = 10
Output: 3 7
Explanation: There are two possiblities 3, 7 & 5, 5 are both prime & their sum is 10, but we'll pick 3, 7 as 3 < 5.
Input: n = 3
Output: -1 -1
Explanation: There are no solutions to the number 3.
*/

class Solution {
  public:
    vector<int> getPrimes(int n) {
         int check[n+1];
 memset(check,0,sizeof(check));
  vector<int> prime;

  for(int i=2;i<n;i++){
     // cout<<i<<" "<<check[i];   
     if(!check[i]){

        prime.push_back(i);
               
     for(int j=2*i;j<=n;j+=i){
       check[j]=1;
     }
}
  }



for(int r:prime){
    // cout<<r;
    if(r>(n+1)/2)
        break;
  
  if(!check[n-r])
    return {r,n-r};

}

return {-1,-1};
    }
};
