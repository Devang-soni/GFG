/*
Given three non-collinear points whose co-ordinates are p(p1, p2), q(q1, q2) and r(r1, r2) in the X-Y plane. Return the number of integral / lattice points strictly inside the triangle formed by these points.
Note: - A point in the X-Y plane is said to be an integral / lattice point if both its coordinates are integral.

Examples

Input: p = (0,0), q = (0,5), r = (5,0)
Output: 6
Input: p = (62,-3), q = (5,-45), r = (-19,-23)
Output: 1129
Explanation: There are 1129 integral points in the triangle formed by p, q and r.
*/

class Solution {
  public:
    long long int gcd(long long int a, long long int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    long long int boundaryPoints(long long int x1, long long int y1, long long int x2, long long int y2) {
        return gcd(abs(x2 - x1), abs(y2 - y1)) + 1;
    }
    long long int InternalCount(long long int p[], long long int q[], long long int r[]) {
         long long int area = abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1])) / 2;
         long long int B = boundaryPoints(p[0], p[1], q[0], q[1]) +
                          boundaryPoints(q[0], q[1], r[0], r[1]) +
                          boundaryPoints(r[0], r[1], p[0], p[1]) - 3;
         long long int I = area - B / 2 + 1;
        return I;
    }
};
