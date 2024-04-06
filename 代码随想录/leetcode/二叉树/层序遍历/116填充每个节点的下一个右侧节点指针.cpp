#include "../header.h"

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        vector<Node*> qu{root};

        while (!qu.empty()) {
            vector<Node*> tmp;
            for (int i = 0; i < qu.size(); i++) {
                if (qu[i]->left) tmp.push_back(qu[i]->left);
                if (qu[i]->right) tmp.push_back(qu[i]->right);
                if (i != qu.size() - 1) {
                    qu[i]->next = qu[i+1];
                }
            }
            qu = std::move(tmp);
        }

        return root;
    }
};