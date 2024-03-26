#include "../header.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        vector<int> res(nums.size());
        int k = nums.size();
        while (l <= r) {
            int t = nums[l] * nums[l];
            int t1 = nums[r] * nums[r];
            if (t > t1) {
                res[--k] = t;
                l++;
            } else {
                res[--k] = t1;
                r--;
            }
        }
        return res;
    }
};