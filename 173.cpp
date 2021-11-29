/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> s;
    
public:
    void addToStack(TreeNode* node) 
    {
        while(node) {
            s.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode* root) 
    {
        addToStack(root);
    }
    
    /** @return the next smallest number */
    int next() 
    {
        TreeNode* smallest = s.top(); 
        s.pop();
        addToStack(smallest->right);
        return smallest->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return (!s.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

