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
    int countNodes(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        return bs(root, 1, max_left_level(root, 1));  //in this solution, height == level
    }
private:
    int bs(TreeNode* t, int l, int h)
    {
        if(l == h)       //if left child and right child is NULL, then l == h, return 1
            return 1;
        if(max_left_level(t->right, l+1) == h)
            return (1 << (h-l)) + bs(t->right, l+1, h);  //1<<(h-l) means 2^(h-l)-1+1
        else
            return (1 << (h-l-1)) + bs(t->left, l+1, h);
    }
    
    int max_left_level(TreeNode* t, int level)
    {   
    	while(t != NULL){
            ++level;   //level will be real level+1
            t = t->left;
        }
        return --level;  //return real level

    }
};
