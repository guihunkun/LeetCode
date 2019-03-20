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
    void inorder(TreeNode* T, vector<int>& multiNums, int& curTimes, int& maxTimes, int& preNum) //��������ĵݹ���ú���
    {
        if(T->left) //�����������Ϊ��,����������
            inorder(T->left, multiNums, curTimes, maxTimes, preNum);
        curTimes = preNum == T->val ? curTimes + 1 : 1; //���µ�ǰԪ�س��ֵĴ���
        if(curTimes > maxTimes) //����maxTimes�������ָ����maxTimesʱ���������֮���ٴ��統ǰԪ��
        {
            maxTimes = curTimes;
            multiNums.clear(); 
            multiNums.push_back(T->val);
        }
        else if(curTimes == maxTimes)
        { //���ʱ�ͽ���ǰԪ��Ҳ��������
            multiNums.push_back(T->val);
        }
        preNum = T->val; //����preNum
        if(T->right)//����������
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

