class Solution 
{
public:
	unordered_map<string, int> m_name_fre;//不需要排序应该用无序，比有序map效率提升不是一点半点
	unordered_map<string, string> m_parrent;
	string find(string name)//查操作，通过递归一直查到祖先，并且将路径上其他节点的父节点设置为祖先
	{
		if(m_parrent.count(name) == 0)
			return name;
		string root = find(m_parrent[name]);
		m_parrent[name]=root;
		return root;
	}
	void m_union(string n1, string n2)//并操作，将n1n2并为一类
	{
		n1 = find(n1);
		n2 = find(n2);
		if (n1 != n2)
		{
			//字典序比较
			if (n1 < n2)
				m_parrent[n2] = n1;
			else
				m_parrent[n1] = n2;
		}
	}
	vector<string> trulyMostPopular(const vector<string>& names, vector<string>& synonyms) 
    {
		//对每个共同使用的名字对，进行并操作
		for (auto& name : synonyms)
		{
			int pos = name.find(',');
			string n1 = name.substr(1, pos - 1);
			string n2 = name.substr(pos + 1, name.size() - pos - 2);
			m_union(n1,n2);
		}
		//将每个被使用的名字和其频率加入map
		for (auto& name : names)
		{
			int pos = name.find('(');
			string nm = name.substr(0, pos);
			int ifre = stoi(name.substr(pos + 1, name.size() - pos - 2));
			m_name_fre[find(nm)] += ifre;
		}
		//保存结果
		vector<string> result;
		for (auto& name : m_name_fre)
		{
			string fre = to_string(name.second);
			result.push_back(name.first + "(" + fre + ")");
		}
		return result;
	}
};
