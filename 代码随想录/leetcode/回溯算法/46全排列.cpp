#include "../header.h"

class Solution {
public:

    void func(vector<int>& nums, vector<vector<int>>& res, vector<int>& p, vector<bool>& v) {
        if (p.size() == nums.size()) {
            res.push_back(p);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (v[i] == true) continue;
            v[i] = true;
            p.push_back(nums[i]);
            func(nums, res, p, v);
            v[i] = false;
            p.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> p;

        vector<bool> v(nums.size(), false);

        func(nums, res, p, v);

        return res;
    }
};