#include "../header.h"

class Solution {
public:
    TreeNode* func(vector<int>& nums, int b, int e) {
        if (b >= e) {
            return nullptr;
        }

        int m = (e - b) / 2 + b;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = func(nums, b, m);
        root->right = func(nums, m + 1, e);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums, 0, nums.size());
    }
};