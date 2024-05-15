#include "../header.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            n += nums[i];
        }

        if (n % 2) {
            return false;
        }

        n /= 2;
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            dp[]
        }
    }
};