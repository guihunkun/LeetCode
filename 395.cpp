class Solution 
{
public:
	int k;
	int longestSubstring(string s, int k) 
    {
		this->k = k;
		return cnt(s,0,s.size()-1);
	}
	int cnt(string& s, int l, int r)
	{
		unordered_map<char, int> ch;
		for(int i = l; i <= r; i++)//统计每个字符出现的次数
		{
			ch[s[i]]++;
		}	
		//从左到右和从右到左分别跳过字符串中不符合的字符，直到遇到符合的字符位置为止
		while(l<=r&&ch[s[l]]<k)
		{
			l++;
		}
		while(l<=r&&ch[s[r]]<k)
		{
			r--;
		}
		if(r - l + 1 < k) 
            return 0;//此时该子串size小于k，不存在
		//寻找分割位置
		//如果在l和r和范围内遇到不满足>=k的，即为分割位置
		int partition = l;
		while(partition<=r&&ch[s[partition]]>=k)
		{
			partition++;
		}
		if(partition >= r) 
            return r - l + 1;//分割位置不存在，说明此时的串符合要求
		//存在分割位置，则取其左右子串两者的最大值
		return max(cnt(s, l, partition - 1), cnt(s, partition + 1, r));
	}
};
