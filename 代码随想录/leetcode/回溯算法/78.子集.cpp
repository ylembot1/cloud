#include "../header.h"

class Solution {
public:
    void func(vector<int>& nums, vector<vector<int>>& res, vector<int>& p, int&& idx) {
        res.push_back(p);
        for (int i = idx; i < nums.size(); i++) {
            p.push_back(nums[i]);
            func(nums, res, p, i + 1);
            p.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> p;
        
        func(nums, res, p, 0);

        return res;
    }
};