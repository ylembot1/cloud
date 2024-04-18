#include "../header.h"

// 当p 和 q分别在root两边时，此时root就是最优解；
// 当p 和 q在root某一边时，此时root不是，而应该是某一边；
// 当某个节点是p或者q时，此时祖先节点一定是上层节点，可以返回，不需要继续dfs了；
class Solution {
public:
    // 后序遍历
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root == p || root == q) {
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        // p、q在左右两边，此节点就是最优解
        if (l != nullptr && r != nullptr) {
            return root;
        }
        
        // 如果左不为空，右为空，说明右边一个节点都没有，p、q的祖先在左边；反之类似；
        return l != nullptr? l : r;
    }
};