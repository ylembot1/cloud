#include "../header.h"

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int> > res;
        queue<Node*> qu;
        qu.push(root);

        while (!qu.empty()) {
            vector<int> t;
            for (int i = qu.size(); i > 0; i--) {
                Node* node = qu.front();
                qu.pop();
                if (node) {
                    t.push_back(node->val);
                    for (int j = 0; j < node->children.size(); j++) {
                        qu.push(node->children[j]);
                    }
                }
            }
            res.push_back(t);
        }
        return res;
    }
};