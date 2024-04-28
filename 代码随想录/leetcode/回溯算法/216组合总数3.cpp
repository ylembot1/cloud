#include "../header.h"

class Solution {
public:
    void func(int& k, int& n, int idx, int&& cur, vector<vector<int>>& res, vector<int>& p) {
        if (p.size() == k) {
            if (cur == n) {
                res.push_back(p);
            }
            return;
        }

        for (int i = idx; i <= 9; i++) {
            p.push_back(i);
            cur += i;
            func(k, n, i + 1, std::move(cur), res, p);
            p.pop_back();
            cur -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> p;
        
        func(k, n, 1, 0, res, p);

        return res;
    }
};