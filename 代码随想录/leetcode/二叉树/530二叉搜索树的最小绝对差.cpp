#include "../header.h"

class Solution {
public:
    void func(int& min, int& pre, TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        func(min, pre, root->left);

        int gap = root->val - pre;
        min = std::min(min, gap);
        pre = root->val;

        func(min, pre, root->right);

    }

    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int pre = -1000000;
        int min = INT_MAX;

        func(min, pre, root);

        return min;
    }
};