#include "../header.h"

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return root;
        }
        if (root->val == val) {
            return root;
        }

        if (val < root->val) {
            return searchBST(root->left, val);
        }

        return searchBST(root->right, val);
    }
};