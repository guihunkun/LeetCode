#include"iostream"
#include"vector"
#include"queue"
#include"stack"
#include"algorithm"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
	
	// ¶þ²æÊ÷µÄ×î´óÉî¶È LeetCode 104 
	int maxDepth(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        int maxle=maxDepth(root->left);
        int maxri=maxDepth(root->right);
        return  max(maxle,maxri)+1;
    }
    
    
	// Ç°Ðò±éÀú µÝ¹é 
	vector<int> preorder(TreeNode* root) 
	{
        vector<int> res;
        preorder(root, res);
        return res;
    }
    
    void preorder(TreeNode* root, vector<int> &res)
	{
		if(root == NULL) 
			return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right,res);
	} 
    
    // Ç°Ðò±éÀú ·ÇµÝ¹é 
    vector<int> preorder_(TreeNode* root) 
	{
        vector<int> res;
        if(root == NULL)
        	return res;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty())
        {
        	TreeNode* node = sta.top();
        	sta.pop();
        	res.push_back(node->val);
        	
			if(node->right)
				sta.push(node->right);
			if(node->left)
				sta.push(node->left);
		}
		return res;
    }
    
    
    
    // ÖÐÐò±éÀú µÝ¹é 
    vector<int> inorder(TreeNode* root) 
    {
    	vector<int> res;
    	inorder(root,res);
		return res;    	
	}
	
    void inorder(TreeNode* root, vector<int> &res) 
	{
        if(root == NULL)
			return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    // ÖÐÐò±éÀú ·ÇµÝ¹é 
    vector<int> inorder_(TreeNode* root) 
	{
        vector<int> res;
        if(root == NULL)
        	return res;
        stack<TreeNode*> sta;
        TreeNode* node = root;
		while(!sta.empty() || node != NULL)
		{
			while(node != NULL)
			{
				sta.push(node);
				node = node->left;	
			}	
			if(!sta.empty())
			{
				node = sta.top();
				sta.pop();
				res.push_back(node->val);
				node = node->right;
			}
		} 
		return res;
    }
    
    
    // ºóÐò±éÀú µÝ¹é 
    vector<int> postorder(TreeNode* root) 
    {
    	vector<int> res;
    	postorder(root, res);
		return res; 
	}
	
    void postorder(TreeNode* root, vector<int> &res) 
	{
        if(root == NULL) 
			return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
    
    // ºóÐò±éÀú ·ÇµÝ¹é  ÊµÏÖ1£º 
    
	/*
	vector<int> postorder_(TreeNode* root) 
	{
		vector<int> res;     
	    stack< pair<TreeNode *, bool> > s;
	    s.push(make_pair(root, false));
	    bool visited;
	    while(!s.empty())
	    {
	        root = s.top().first;
	        visited = s.top().second;
	        s.pop();
	        if(root == NULL)
	            continue;
	        if(visited)
	        {
	            res.push_back(root->val);
	        }
	        else
	        {
	            s.push(make_pair(root, true));
	            s.push(make_pair(root->right, false));
	            s.push(make_pair(root->left, false));
	        }
	    }
		return res;
    }
    */
    // ºóÐò±éÀú ·ÇµÝ¹é  ÊµÏÖ2£º 
    vector<int> postorder_(TreeNode* root) 
	{
		vector<int> res;     
        if (root == NULL) 
			return res;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty()) 
		{
			TreeNode* node = sta.top();
			sta.pop();
            res.push_back(node->val);
            // ÊµÏÖÄæÐò
            if(node->left)
				sta.push(node->left);
            if(node->right)
				sta.push(node->right);
			
        }
        // ½«½á¹û½øÐÐÄæÐò
        reverse(res.begin(), res.end());
		return res;
    }
    
    
    // ²ãÐò±éÀú ÊµÏÖ1£º
	/* 
    vector<vector<int> > levelOrder(TreeNode* root) 
    {
        vector<vector<int> > res;
        if(root==NULL)
            return  res;
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            TreeNode* node=q.front().first;
            int level=q.front().second;
            q.pop();
            if(level==res.size())
                res.push_back(vector<int>());
            res[level].push_back(node->val);
            if(node->left)
                q.push(make_pair(node->left,level+1));
            if(node->right)
                q.push(make_pair(node->right,level+1));
        }
        return res;
    }
    */
    // ²ãÐò±éÀú ÊµÏÖ2£º
	vector<vector<int> > levelOrder(TreeNode* root) 
    {
        vector<vector<int> > res;
        vector<int> r;
        if(root==NULL)
            return  res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
        	r.clear();
        	int count = q.size();
        	while(count > 0)
        	{
        		TreeNode* node=q.front();
        		r.push_back(node->val);
        		q.pop();
        		count--;
        		if(node->left)
                	q.push(node->left);
            	if(node->right)
                	q.push(node->right);
			}
            res.push_back(r);           
        }
        return res;
    }


    // ²ãÐò´òÓ¡
	void printlevelorderTreeNode(vector<vector<int> > &ress)
    {
    	for(int i = 0; i < ress.size(); i++)
    	{
    		for(int j = 0; j < ress[i].size(); j++)
    			cout<<ress[i][j]<<" ";
    		cout<<endl;
		}	
	}
	
	
    // Ç°ÖÐºóÐò´òÓ¡ 
    void printorderTreeNode(vector<int> &res)
    {
    	for(int i = 0; i < res.size(); i++)
    		cout<<res[i]<<" ";
	}

	TreeNode* helperInPos(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int postart, int poend)
    {
        if(instart > inend || postart > poend)
            return NULL;
        TreeNode *node = new TreeNode(postorder[poend]);
        int i = 0;
        //¿¿¿¿¿¿¿¿¿¿¿¿
        for(i = instart; i< inorder.size(); i++)
        {
            if(inorder[i] == node->val)
                break;
        }
        //i-instart¿inorder¿¿¿¿¿¿¿¿¿¿¿¿¿
        node->left = helper(inorder, postorder, instart, i - 1, postart, postart + i - instart - 1);
        node->right = helper(inorder, postorder, i + 1, inend , postart + i - instart, poend - 1);
        return node;
    }

	TreeNode* helperPreIn(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend)
	{
		if(prestart > preend || instart > inend)
		{
			return NULL;
		}

		TreeNode* node =new TreeNode(preorder[prestart]);
		int i;
		for(i = instart; i <= inend; i++)
		{
			if(inorder[i] == node->val)
			{
				break;
			}
		}

		node->left=helperPreIn(preorder, inorder, prestart + 1, prestart + i - instart, instart, i - 1);
		node->right=helperPreIn(preorder , inorder, prestart + i - instart + 1, preend, i + 1, inend);
		return node;
	}
	
	// ¿¿¿¿¿¿¿¿¿¿¿¿
	TreeNode* buildTreeInPos(vector<int>& inorder, vector<int>& postorder) 
	{
        return helperInPos(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);    
    }


	// ¿¿¿¿¿¿¿¿¿¿¿¿
    TreeNode* buildTreePreIn(vector<int>& preorder, vector<int>& inorder) 
    {
        return helperPreIn(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }




		
	 
};
int main()
{
	//****°¸Àý1**** 
	    /////////////////
        //      5      //
        //    /   \    //
        //   3    6    //
        //  / \    \   //
        // 2  4     8  //
        /////////////////
    TreeNode* root;
    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left= new TreeNode(2);
    root->left->right= new TreeNode(4);
    root->right->right= new TreeNode(8);
    
     
    
    vector<int> res;
    
    // µÝ¹éÇ°ÖÐºóÐò±éÀú
	cout<<"****µÝ¹éÇ°ÖÐºóÐò±éÀú****"<<endl;
	
    // Ç°Ðò±éÀú
    cout<<"****Ç°Ðò±éÀú µÝ¹é****"<<endl;
	res = Solution().preorder(root);
	Solution().printorderTreeNode(res);
	cout<<endl<<endl;
		
	// ÖÐÐò±éÀú
	cout<<"****ÖÐÐò±éÀú µÝ¹é****"<<endl; 
	res = Solution().inorder(root);
	Solution().printorderTreeNode(res);
	cout<<endl<<endl;
	
	// ºóÐò±éÀú
	cout<<"****ºóÐò±éÀú µÝ¹é****"<<endl; 
	res = Solution().postorder(root);
	Solution().printorderTreeNode(res);
	cout<<endl<<endl;
	
	
	cout<<endl<<endl;
	
	
	// ·ÇµÝ¹éÇ°ÖÐºóÐò±éÀú
	cout<<"****·ÇµÝ¹éÇ°ÖÐºóÐò±éÀú****"<<endl;
	
    // Ç°Ðò±éÀú ·ÇµÝ¹é 
    cout<<"****Ç°Ðò±éÀú ·ÇµÝ¹é****"<<endl;
	res = Solution().preorder_(root); 
	Solution().printorderTreeNode(res);
	cout<<endl<<endl;
	
	// ÖÐÐò±éÀú ·ÇµÝ¹é 
	cout<<"****ÖÐÐò±éÀú ·ÇµÝ¹é****"<<endl; 
	res = Solution().inorder_(root);
	Solution().printorderTreeNode(res);
	cout<<endl<<endl;
	
	// ºóÐò±éÀú ·ÇµÝ¹é 
	cout<<"****ºóÐò±éÀú ·ÇµÝ¹é****"<<endl; 
	res = Solution().postorder_(root);
	Solution().printorderTreeNode(res);
	cout<<endl<<endl;
	
	
	// ²ãÐò±éÀú
	cout<<"****²ãÐò±éÀú****"<<endl; 
	vector<vector<int> > ress;
	ress = Solution().levelOrder(root);
	Solution().printlevelorderTreeNode(ress);
	cout<<endl; 
	
	
    return 0;
} 
