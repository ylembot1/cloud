#include "../header.h"


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            vector<int> tmp;
            for (int i = qu.size(); i > 0; i--) {
                TreeNode* t = qu.front();
                qu.pop();
                if (t) {
                    tmp.push_back(t->val);
                    qu.push(t->left);
                    qu.push(t->right);
                }
            }
            if (!tmp.empty()) {
                res.push_back(tmp);
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};