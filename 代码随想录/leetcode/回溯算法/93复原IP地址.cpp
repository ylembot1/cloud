#include "../header.h"

class Solution {
public:
    void func(vector<string>& res, string& s, int&& idx, int&& pn, string&& p) {
        if (idx == s.size() && pn == 4) {
            res.push_back(p);
            return;
        }

        string tmp = "";
        for (int i = idx; i < s.size(); i++) {
            tmp += s[i];
            if (tmp.size() > 1 && tmp[0] == '0') {
                break;
            }

            int t = atoi(tmp.c_str());
            if (t > 255) {
                break;
            }

            if (p != "") {
                func(res, s, i + 1, pn + 1, p + "." + tmp);
            } else {
                func(res, s, i + 1, pn + 1, std::move(tmp));
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        
        func(res, s, 0, 0, "");

        return res;
    }
};