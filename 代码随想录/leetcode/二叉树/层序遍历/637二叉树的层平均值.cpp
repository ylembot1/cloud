#include "../header.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> qu;
        qu.push(root);

        while (!qu.empty()) {
            double t = 0;
            int size = qu.size();
            for (int i = qu.size(); i > 0; i--) {
                TreeNode* r = qu.front();
                qu.pop();
                if (r) {
                    t += r->val;
                    if (r->left) qu.push(r->left);
                    if (r->right) qu.push(r->right);
                }
            }
            res.push_back(t / size);
        }

        return res;
    }
};