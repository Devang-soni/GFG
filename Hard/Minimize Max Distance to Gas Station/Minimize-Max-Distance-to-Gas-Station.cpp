/*
We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where n = size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.

Example 1:

Input:
n = 10
stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 9
Output: 0.50
Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
Example 2:

Input:
n = 10
stations = [3,6,12,19,33,44,67,72,89,95] 
k = 2 
Output: 14.00 
Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.
*/

class Solution {
   
  public:
  double findSmallestMaxDist(vector<int>& stations, int k) {
        int n = stations.size();
        
        auto canAchieve = [&](double d) {
            int required = 0;
            for (int i = 1; i < n; ++i) {
                int gap = stations[i] - stations[i-1];
                required += static_cast<int>((gap / d));
            }
            return required <= k;
        };
        
        double left = 0.0;
        double right = stations[n-1] - stations[0];
  
        while (right - left > 1e-6) {
            double mid = (left + right) / 2.0;
            if (canAchieve(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        return round(right * 100) / 100; 
  
    }
};
