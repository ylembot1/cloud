#include "../header.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;
        while (r < nums.size()) {
            if (nums[r] == nums[l]) {
                r++;
            } else {
                nums[++l] = nums[r++];
            }
        }
        return l + 1;
    }
};