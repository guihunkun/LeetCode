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
    void inorder(TreeNode* T, vector<int>& multiNums, int& curTimes, int& maxTimes, int& preNum) //中序遍历的递归调用函数
    {
        if(T->left) //如果左子树不为空,遍历左子树
            inorder(T->left, multiNums, curTimes, maxTimes, preNum);
        curTimes = preNum == T->val ? curTimes + 1 : 1; //更新当前元素出现的次数
        if(curTimes > maxTimes) //更新maxTimes，当出现更大的maxTimes时，数组清空之后再存如当前元素
        {
            maxTimes = curTimes;
            multiNums.clear(); 
            multiNums.push_back(T->val);
        }
        else if(curTimes == maxTimes)
        { //相等时就将当前元素也存入数组
            multiNums.push_back(T->val);
        }
        preNum = T->val; //更新preNum
        if(T->right)//遍历右子树
            inorder(T->right, multiNums, curTimes, maxTimes, preNum);
    }
    vector<int> findMode(TreeNode* root) 
    {
        vector<int> res;
        if(root == NULL)
            return res;
        int curTimes = 1, maxTimes = 0, preNum = INT_MIN;
        inorder(root, res, curTimes, maxTimes, preNum);
        return res;
    }
};

