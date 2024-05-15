#include "../header.h"

// 题目要求子序列，这个方法不满足
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int res = 1;
//         if (nums.size() <= 1) {
//             return res;
//         }

//         int i = 0;
//         int t = nums[1] - nums[0];
//         for (int j = 2; j < nums.size(); j++) {
//             int m = t * (nums[j] - nums[j - 1]);
//             if (m >= 0) {
//                 res = std::max(res, j - i);
//                 i = j - 1;
//             }
//             t = nums[j] - nums[j - 1];
//         }

//         return res;
//     }
// };

// 动态规划
// o(n^2)复杂度
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1;
        
        vector<int> h(nums.size(), 1);
        vector<int> l(nums.size(), 1);

        int ret = 1;
        for (int i = 1; i < nums.size(); i++) {
            int mh = 1;
            int ml = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    ml = std::max(ml, h[j] + 1);
                } else if (nums[i] < nums[j]) {
                    mh = std::max(mh, l[j] + 1);
                }
            }
            h[i] = mh;
            l[i] = ml;
        }

        return std::max(h[nums.size() - 1], l[nums.size() - 1]);
    }
};