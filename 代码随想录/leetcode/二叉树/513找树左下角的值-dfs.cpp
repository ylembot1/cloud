#include "../header.h"

class Solution {
public:
    int maxDep = 0;

    void func(TreeNode* root, int& res, int&& dep) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (dep > maxDep) {
                maxDep = dep;
                res = root->val;
                return;
            }
        }

        func(root->left, res, dep + 1);
        func(root->right, res, dep + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        int res = 0;
        
        func(root, res, 1);

        return res;
    }
};