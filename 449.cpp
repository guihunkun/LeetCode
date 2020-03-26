/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{
public:
    void num2str(int val,string& data)
    {
        string tmp;
        while(val)
        {
            tmp += val%10 + '0';
            val = val / 10;
        }
        for(int i=tmp.length()-1;i>=0;i--)
        {
            data += tmp[i];
        }
        data += "#" ; 

    }
    void BST_preorder(TreeNode*root,string& data)
    {
        if(!root)
        {
            return;
        }
        string str_val;
        num2str(root->val,str_val);
        data += str_val;
        BST_preorder(root->left,data);
        BST_preorder(root->right,data);
    }
    void BST_insert(TreeNode* root,TreeNode* insert_node)
    {
        if(root->val > insert_node->val)
        {
            if(root->left)
            {
                BST_insert(root->left,insert_node);
            }
            else
            {
                root->left=insert_node;
            }
        }else
        {
            if(root->right)
            {
                BST_insert(root->right,insert_node);
            }
            else
            {
                root->right=insert_node;
            }
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string data;
        BST_preorder(root,data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> vec;
        int val=0;
        if(data.length() == 0)
        {
            return NULL;
        }
        for(int i=0;i<data.length();i++)
        {
            if(data[i] == '#')
            {
                vec.push_back(new TreeNode(val));
                val=0;
            }else
            {
                val=val*10 + data[i] - '0';
            }
        }
        for(int i=1;i<vec.size();i++)
        {
            BST_insert(vec[0],vec[i]);
        }
        return vec[0];
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
