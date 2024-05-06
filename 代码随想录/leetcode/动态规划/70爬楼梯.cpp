#include "../header.h"

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int n2 = 1, int n1 = 2;
        for (int i = 3; i <= n; i++) {
            int tn = n2 + n1;
            n2 = n1;
            n1 = tn;
        }
        return n1;
    }

};