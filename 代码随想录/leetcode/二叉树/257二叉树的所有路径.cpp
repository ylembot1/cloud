#include "../header.h"

class Solution {
public:
    void func(vector<string>& res, TreeNode* root, string&& str) {
        if (root == nullptr) {
            return;
        }

        string tmp = "";
        if (str != "") {
            tmp = str + "->" + std::to_string(root->val);
        } else {
            tmp = std::to_string(root->val);
        }

        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(std::move(tmp));
            return;
        }

        func(res, root->left, std::move(tmp));
        func(res, root->right, std::move(tmp));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) {
            return res;
        }

        func(res, root, "");

        return res;
    }
};