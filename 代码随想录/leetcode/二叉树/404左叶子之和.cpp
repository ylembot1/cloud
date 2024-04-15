#include "../header.h"


class Solution {
public:
    // int res = 0;
    int sumOfLeftLeaves(TreeNode* root, int& res = 0) {
        if (root == nullptr) {
            return res;
        }

        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            res += root->left->val;
        }

        sumOfLeftLeaves(root->left, res);
        sumOfLeftLeaves(root->right, res);

        return res;
    }
};