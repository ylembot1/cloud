#include "../header.h"

class Solution {
public:

    void func(TreeNode* root, int& val) {
        if (root == nullptr) {
            return;
        }
        func(root->right, val);

        root->val += val;
        val = root->val;

        func(root->left, val);
    }

    TreeNode* convertBST(TreeNode* root) {
        int val = 0;
        func(root, val);

        return root;
    }
};