#include "../header.h"

class Solution {
public:

    void func(vector<int>& candidates, int& target, vector<vector<int>>& res, vector<int>& p, int&& cur, int&& idx) {
        if (cur == target) {
            res.push_back(p);
            return;
        }

        if (cur > target) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            p.push_back(candidates[i]);
            func(candidates, target, res, p, cur + candidates[i], std::move(i));
            p.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> p;

        // 不需要sort
        // sort(candidates.begin(), candidates.end());
        
        // 需要使用idx，用来去重
        func(candidates, target, res, p, 0, 0);

        return res;
    }
};