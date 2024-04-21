#include "../header.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);

        unordered_map<int, int> mp;
        for (int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]] = i;
        }

        stack<int> st;
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                if (mp.find(nums2[st.top()]) == mp.end()) {
                    st.pop();
                    continue;
                }
                res[mp[nums2[st.top()]]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};