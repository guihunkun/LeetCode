class Solution 
{
public:
	vector<string> wordBreak(string s, vector<string>& wordDict)
	{
		if(!wordBreak_139(s, wordDict)) 
            		return {};
		size_t validEnd = 0;
		vector<vector<string>> dp(s.size() + 1, vector<string>());
		for(size_t i = 0; i < s.size(); i++)
		{
			if(i == validEnd + 1) 
                return {};
			if(i != 0 && dp[i].empty()) 
                continue;
			for(auto& word : wordDict)
			{
				size_t newEnd = i + word.size();
				if(newEnd > s.size()) 
                    continue;
				if(memcmp(&s[i], &word[0], word.size()) != 0) 
                    continue;
				validEnd = max(validEnd, newEnd);
				if(i == 0)
				{
					dp[newEnd].push_back(word);
					continue;
				}
				for(auto& d : dp[i])
				{
					dp[newEnd].push_back(d + " " + word);
				}
			}
		}
		return dp.back();
	}

	bool wordBreak_139(string& s, vector<string>& wordDict)
	{
		size_t validEnd = 0;
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for(size_t i = 0; i < s.size(); i++)
		{
			if(i == validEnd + 1) 
                return false;
			if(!dp[i]) 
                continue;
			for(auto& word : wordDict)
			{
				size_t newEnd = i + word.size();
				if(newEnd > s.size()) 
                    continue;
				if(memcmp(&s[i], &word[0], word.size()) == 0)
				{
					dp[newEnd] = true;
					validEnd = max(validEnd, newEnd);
				}
			}
		}
		return dp.back();
	}
};

