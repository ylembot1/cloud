#include "../header.h"

class Solution {
public:
    void func(TreeNode* root, vector<int>& res, int& max_cur, int& cur, int& cur_num) {
        if (root == nullptr) {
            return;
        }

        func(root->left, res, max_cur, cur, cur_num);

        if (root->val == cur_num) {
            cur++;
        } else {
            if (max_cur < cur) {
                res.clear();
                max_cur = cur;
                res.push_back(cur_num);
            } else if (max_cur == cur) {
                res.push_back(cur_num);
            }
            cur = 1;
            cur_num = root->val;
        }

        func(root->right, res, max_cur, cur, cur_num);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> res;

        int max_cur = 0;
        int cur = 0;
        int cur_num = INT_MIN;

        func(root, res, max_cur, cur, cur_num);

        if (max_cur < cur) {
            res.clear();
            res.push_back(cur_num);
        } else if (max_cur == cur) {
            res.push_back(cur_num);
        }
        return res;
    }
};