#include "../header.h"

class Solution {
public:
    int func(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            }
        }
        if (r == nums.size() - 1) {
            return nums[r] == target? r: -1;
        }
        return nums[r + 1] == target? r + 1: -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }

        int low = func(nums, target);

        if (low == -1) {
            return {-1, -1};
        }

        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid;
            }
        }
        return {low, l == 0? 0: l - 1};
    }
};