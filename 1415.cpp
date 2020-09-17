class Solution 
{
public:
	vector<string> v;
	string getHappyString(int n, int k) 
    {
		dfs(n, 0, "");
		int size = v.size();
		if(size < k)
            return "";
		else 
            return v[k - 1];
	}
	void dfs(int n, int cur, string tmp)
    {
		if(cur == n)
        {
			v.push_back(tmp);
			return;
		}			
		if(check(tmp, 'a'))
            dfs(n, cur + 1, tmp + 'a');
		if(check(tmp, 'b'))
            dfs(n, cur + 1, tmp + 'b');
		if(check(tmp, 'c'))
            dfs(n, cur + 1, tmp + 'c');
	}
	bool check(string &tmp,char a)
    {
		if(tmp.empty())
            return true;
		return tmp[tmp.size() - 1] != a;
	}
};
