#include "../header.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int min = INT_MAX;
        if (root->left != nullptr) {
            min = std::min(minDepth(root->left), min);
        }
        if (root->right != nullptr) {
            min = std::min(minDepth(root->right), min);
        }

        return min + 1;
    }
};