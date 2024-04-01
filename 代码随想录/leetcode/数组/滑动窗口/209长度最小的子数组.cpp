#include "../header.h"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int res = nums.size() + 1;
        int win = 0;

        while (r < nums.size()) {
            win += nums[r++];
            while (win >= target) {
                res = std::min(res, r - l);
                win -= nums[l++];
            }
        }

        return res == nums.size() + 1? 0: res;
    }
};