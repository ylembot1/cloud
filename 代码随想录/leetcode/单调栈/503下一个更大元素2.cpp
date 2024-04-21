#include "../header.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        
        stack<int> st;
        int n = nums.size() * 2;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i % nums.size()] > nums[st.top()]) {
                res[st.top()] = nums[i % nums.size()];
                st.pop();
            }

            st.push(i % nums.size());
        }

        return res;
    }
};