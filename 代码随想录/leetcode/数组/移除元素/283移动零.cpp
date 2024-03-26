#include "../header.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0;
        while (r < nums.size()) {
            if (nums[r] == 0) {
                r++;
                continue;
            } else {
                std::swap(nums[l], nums[r]);
                l++;
                r++;
            }
        }
    }
};