#include "../header.h"

class Solution {
public:

    TreeNode* func(vector<int>& nums, int b, int e) {
        if (b >= e) {
            return nullptr;
        }

        int max = -1;
        int idx;
        for (int i = b; i < e; i++) {
            if (max < nums[i]) {
                max = nums[i];
                idx = i;
            }
        }

        TreeNode* root = new TreeNode(max);
        root->left = func(nums, b, idx);
        root->right = func(nums, idx + 1, e);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return func(nums, 0, nums.size());
    }
};