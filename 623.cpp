/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int v, int d, int k) {
        if (root == NULL) return;
        if (k == d - 1) {
            TreeNode* lnode = new TreeNode(v);
            TreeNode* rnode = new TreeNode(v);
            lnode->left = root->left;
            rnode->right = root->right;
            root->left = lnode;
            root->right = rnode;
            return;
        }
        dfs(root->left, v, d, k + 1);
        dfs(root->right, v, d, k + 1);
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        dfs(root, v, d, 1);
        return root;
    }
};
