#include "../header.h"

class Solution {
public:
    void func(vector<int>& candidates, int& target, 
        vector<vector<int>>& res, vector<int>& p, vector<bool>& v, int&& idx) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(p);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i != 0 && candidates[i] == candidates[i - 1] && v[i - 1] == false) {
                continue;
            }
            if (v[i] == false) {
                v[i] = true;
                target -= candidates[i];
                p.push_back(candidates[i]);
                func(candidates, target, res, p, v, i + 1);
                target += candidates[i];
                p.pop_back();
                v[i] = false;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> p;
        vector<bool> v(candidates.size(), false);
        
        sort(candidates.begin(), candidates.end());
        func(candidates, target, res, p, v, 0);

        return res;
    }
};