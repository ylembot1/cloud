#include "../header.h"

class Solution {
public:
    int getD(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(getD(root->left), getD(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if (!isBalanced(root->left)) {
            return false;
        }
        if (!isBalanced(root->right)) {
            return false;
        }

        int dl = getD(root->left);
        int dr = getD(root->right);

        if (std::abs(dl - dr) <= 1) {
            return true;
        }
        return false;
    }
};