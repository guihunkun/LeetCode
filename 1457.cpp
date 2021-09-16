/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int check(int *cnt) {
        int odd = 0;
        for(int i = 0; i <= 9; i++) {
            if(cnt[i]&1) {
                odd++;
            }
        }
        if(odd <= 1) {
            return 1;
        }
        return 0;
    }
    int dfs(TreeNode *root, int *cnt) {
        if(root == nullptr) {
            return 0;
        }
        cnt[root->val] ++;
        if(root->left == nullptr && root->right == nullptr) {
            int anw = check(cnt);
            cnt[root->val]--;
            return anw;
        }
        int anw = 0;
        if(root->left != nullptr) {
            anw += dfs(root->left, cnt);
        }
        if(root->right != nullptr) {
            anw += dfs(root->right, cnt);
        }
        cnt[root->val] --;
        return anw;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt[10] = {0};
        return dfs(root, cnt);
    }
};



