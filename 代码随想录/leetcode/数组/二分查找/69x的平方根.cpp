#include "../header.h"

class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x;
        r++;
        while (l < r) {
            long long mid = (r - l) / 2 + l;
            long long t = mid * mid;
            if (t < x) {
                l = mid + 1;
            } else if (t == x) {
                return mid;
            } else {
                r = mid - 1;
            }
        }
        return l * l > x ? l - 1 : l;
    }
};