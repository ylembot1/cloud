#include "../header.h"

class Solution {
public:

    bool func(TreeNode* root, int pathSum, int& targetSum) {
        pathSum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (pathSum == targetSum) {
                return true;
            }
        }

        if (root->left) {
            if (func(root->left, pathSum, targetSum)) {
                return true;
            }
        }
        if (root->right) {
            if (func(root->right, pathSum, targetSum)) {
                return true;
            }
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        int pathSum = 0;
        
        return func(root, pathSum, targetSum);
    }
};