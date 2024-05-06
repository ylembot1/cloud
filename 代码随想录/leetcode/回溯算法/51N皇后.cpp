#include "../header.h"

class Solution {
public:
    int dir[8][2] = {{-1, 1}, {1, -1}, {1, 1}, {-1, -1}, 
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool is(vector<string>& g, int r, int c) {
        for (int d = 0; d < 8; d++) {
            int rr = r, cc = c;
            rr += dir[d][0];
            cc += dir[d][1];
            while (rr >= 0 && rr < g[0].size() && cc >= 0 && cc < g[0].size()) {
                if (g[rr][cc] == 'Q') return false;
                rr += dir[d][0];
                cc += dir[d][1];
            }
        }

        return true;
    }

    void func(vector<vector<string>>& res, vector<string>& g, int r, int n) {
        if (r == n) {
            res.push_back(g);
            return;
        }

        for (int i = 0; i < g[0].size(); i++) {
            g[r][i] = 'Q';
            if (!is(g, r, i)) {
                g[r][i] = '.';
                continue;
            }
            r++;
            func(res, g, r, n);
            r--;
            g[r][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        string str = "";
        for (int i = 0; i < n; i++) {
            str += ".";
        }

        vector<string> g(n, str);
        func(res, g, 0, n);

        return res;
    }
};