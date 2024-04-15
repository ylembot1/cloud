#include "../header.h"

class Solution {
public:

    TreeNode* func(vector<int>& inorder, int ib, int ie, vector<int>& postorder, int pi) {
        if (ib >= ie) {
            return nullptr;
        }

        int idx = ib;
        for (int i = ib; i < ie; i++) {
            if (inorder[i] == postorder[pi]) {
                idx = i;
                break;
            }
        }

        int len = ie - idx;
        TreeNode* root = new TreeNode(inorder[idx]);
        root->left = func(inorder, ib, idx, postorder, pi - len);
        root->right = func(inorder, idx + 1, ie, postorder, pi - 1);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return func(inorder, 0, inorder.size(), postorder, postorder.size() - 1);
    }
};