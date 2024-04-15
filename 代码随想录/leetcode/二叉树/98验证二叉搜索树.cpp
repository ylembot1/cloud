#include "../header.h"

class Solution {
public:

    bool func(TreeNode* root, long long min, long long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            return false;
        }

        return func(root->left, min, root->val) && func(root->right, root->val, max);

    }

    bool isValidBST(TreeNode* root) {
        long long min = INT64_MIN;
        long long max = INT64_MAX;
        return func(root, min, max);
    }
};