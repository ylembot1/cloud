#include "../header.h"

class Solution {
public:

    void func(vector<int>& nums, vector<vector<int>>& res, vector<int>& p, int&& idx, 
        vector<bool>& v) {
        if (p.size() >= 2) {
            res.push_back(p);
        }

        for (int i = idx; i < nums.size(); i++) {
            bool c = false;
            for (int j = i - 1; j >= idx; j--) {
                if (nums[j] == nums[i] && v[j] == false) {
                    c = true;
                    break;
                }
            }
            if (c) continue;
            if (p.size() != 0) {
                int t = p[p.size() - 1];
                if (t > nums[i]) {
                    continue;
                }
            } 
            p.push_back(nums[i]);
            v[i] = true;
            func(nums, res, p, i + 1, v);
            v[i] = false;
            p.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> p;
        vector<bool> v(nums.size(), false);

        func(nums, res, p, 0, v);

        return res;
    }
};