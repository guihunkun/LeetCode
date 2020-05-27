/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*, uint64_t>> que; // uint64_t避免越界，理论上最高支持到64层
        int ans = 0;
        if(root) 
        {
            que.push(std::make_pair(root, 0));
        }
        while(!que.empty()) 
        {
            int size = que.size(), left = 0, right = 0;
            for(int i = 0; i < size; ++i) 
            {
                auto node = que.front();
                que.pop();
                if(i == 0) 
                {
                    left = node.second;
                }
                if(i == size - 1) 
                {
                    right = node.second;
                }
                if(node.first->left) 
                {
                    que.push(std::make_pair(node.first->left, 2 * node.second + 1));
                }
                if(node.first->right) 
                {
                    que.push(std::make_pair(node.first->right, 2 * node.second + 2));
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
