#include "../header.h"


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;

        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            vector<int> tmp;
            for (int i = qu.size(); i > 0; i--) {
                TreeNode* t = qu.front();
                if (t != nullptr) {
                    tmp.push_back(t->val);
                    qu.push(t->left);
                    qu.push(t->right);
                }
                qu.pop();
            }
            if (tmp.size() != 0) 
                res.push_back(tmp);
        }

        return res;
    }
};