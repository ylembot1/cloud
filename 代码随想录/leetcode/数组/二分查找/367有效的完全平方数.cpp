#include "../header.h"

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 0, r = num;
        r++;
        while (l < r) {
            long long mid = (r - l) / 2 + l;
            long long t = mid * mid;
            if (t == num) {
                return true;
            } else if (t < num) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        return false;
    }
};