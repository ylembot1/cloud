#include "../header.h"

// 超时
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        
        for (int i = 0; i < temperatures.size(); i++) {
            for (int j = i + 1; j < temperatures.size(); j++) {
                if (temperatures[j] > temperatures[i]) {
                    res[i] = j - i;
                    break;
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        stack<pair<int, int>> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty()) {
                auto top = st.top();
                st.pop();
                if (top.first < temperatures[i]) {
                    res[top.second] = i - top.second;
                } else {
                    st.push(top);
                    break;
                }
            }
            st.push({temperatures[i], i});
        }

        return res;
    }
};


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty()) {
                if (temperatures[st.top()] < temperatures[i]) {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
            }
            st.push(i);
        }

        return res;
    }
};