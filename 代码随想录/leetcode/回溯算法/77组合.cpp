#include "../header.h"

class Solution {
public:

    void func(vector<vector<int>>& res, vector<int>& p, int n, int k, vector<bool>& v, int idx) {
        if (p.size() == k) {
            res.push_back(p);
            return;
        }

        if (n - idx + 1 < k) {
            return;
        }

        for (int i = idx; i <= n; i++) {
            if (v[i] == true) {
                continue;
            }
            v[i] = true;
            p.push_back(i);
            func(res, p, n, k, v, i + 1);
            v[i] = false;
            p.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> p;

        vector<bool> v(n, false);

        func(res, p, n, k, v, 1);

        return res;
    }
};