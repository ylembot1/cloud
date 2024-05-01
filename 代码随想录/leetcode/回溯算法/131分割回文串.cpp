#include "../header.h"

class Solution {
public:
    bool is(string& cur) {
        int i = 0, j = cur.size() - 1;
        while (i < j) {
            if (cur[i] != cur[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void func(vector<vector<string>>& res, vector<string>& p, int idx, string& s) {
        if (idx >= s.size()) {
            res.push_back(p);
            return;
        }

        string cur = "";
        for (int i = idx; i < s.size(); i++) {
            cur += s[i];
            if (!is(cur)) {
                continue;
            }
            p.push_back(cur);
            func(res, p, i + 1, s);
            p.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> p;

        func(res, p, 0, s);

        return res;
    }
};