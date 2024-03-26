#include "../header.h"

class Solution {
public:

    int func(string& s) {
        int sl = -1, sr = 0;
        while (sr < s.size()) {
            if (s[sr] == '#') {
                if (sl >= 0) {
                    sl--;
                }
            } else {
                s[++sl] = s[sr++];
            }
        }
        return sl;
    }

    bool backspaceCompare(string s, string t) {
        int sl = func(s);
        int tl = func(t);

        if (sl != tl) {
            return false;
        }
        for (int i = 0; i <= sl; i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};