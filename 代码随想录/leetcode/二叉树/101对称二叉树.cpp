#include "../header.h"

class Solution {
public:

    bool func(TreeNode* root, TreeNode* root1) {
        if (root == nullptr && root1 == nullptr) {
            return true;
        } else if (root == nullptr || root1 == nullptr) {
            return false;
        }

        if (root->val != root1->val) {
            return false;
        }

        return func(root->left, root1->right) && func(root->right, root1->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return func(root, root);
    }
};