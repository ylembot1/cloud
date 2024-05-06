#include "../header.h"

class Solution {
public:
    // f(n) = min(f(n-1), f(n-2)) + cost(n)

    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[0], int b = cost[1];
        int c = 0;
        for (int i = 2; i < cost.size(); i++) {
            c = std::min(a, b) + cost[i];
            a = b;
            b = c;
        }

        return std::min(a, b);

    }
};