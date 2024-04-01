#include "../header.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)    return {};
        vector<int> res;
        queue<TreeNode*> qu;
        qu.push(root);
        
        while (!qu.empty()) {
            for (int i = qu.size(); i > 0; i--) {
                TreeNode* t = qu.front();
                qu.pop();
                if (i == 1) {
                    res.push_back(t->val);
                }
                if (t->left)
                    qu.push(t->left);
                if (t->right)
                    qu.push(t->right);
            }
        }

        return res;
    }   

};