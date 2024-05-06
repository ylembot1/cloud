#include "../header.h"

class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        int result = 0;
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};