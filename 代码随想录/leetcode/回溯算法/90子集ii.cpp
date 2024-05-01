#include "../header.h"

class Solution {
public:

    void func(vector<int>& nums, vector<vector<int>>& res, vector<int>& p, vector<bool>& v, int&& idx) {
        res.push_back(p);

        for (int i = idx; i < nums.size(); i++) {
            if (i != 0 && nums[i-1] == nums[i] && v[i - 1] == false) {
                continue;
            }
            p.push_back(nums[i]);
            v[i] = true;
            func(nums, res, p, v, i + 1);
            v[i] = false;
            p.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> p;

        vector<bool> v(nums.size(), false);
        sort(nums.begin(), nums.end());
        func(nums, res, p, v, 0);

        return res;
    }
};