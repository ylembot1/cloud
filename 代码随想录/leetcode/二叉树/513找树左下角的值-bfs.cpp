#include "../header.h"


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* res;
        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()) {
            int size = qu.size();
            for (int i = qu.size(); i > 0; i--) {
                TreeNode* tmp = qu.front();
                qu.pop();
                if (i == size) {
                    res = tmp;
                }

                if (tmp->left) {
                    qu.push(tmp->left);
                }
                if (tmp->right) {
                    qu.push(tmp->right);
                }
            }
        }
        return res->val;
    }
};