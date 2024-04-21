#include "../header.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == key) {
            if (root->left == nullptr) {
                return root->right;
            }
            TreeNode* tmp = root->left;
            while (tmp->right != nullptr) {
                tmp = tmp->right;
            }
            tmp->right = root->right;
            return root->left;
        }
        
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);

        return root;
    }
};