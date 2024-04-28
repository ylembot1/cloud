#include "../header.h"

class Solution {
public:

    void func(vector<string>& res, vector<string>& num, string&& p, string& digits, int idx) {
        if (p.size() == digits.size()) {
            res.push_back(p);
            return;
        }

        for (int i = idx; i < digits.size(); i++) {
            for (int j = 0; j < num[(digits[i] - '0')].size(); j++) {
                func(res, num, p+num[(digits[i] - '0')][j], digits, i + 1);

            }
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> num = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        func(res, num, "", digits, 0);

        return res;
    }
};