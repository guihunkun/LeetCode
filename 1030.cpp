class Solution 
{
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) 
    {
        vector<vector<int>> vec;
        multimap<int, pair<int, int>> m;
        for(int i = 0; i<R; i++) 
	{
       	   for(int j = 0; j<C; j++) 
	   {
		int dis = abs(r0 - i) + abs(c0 - j);
		pair<int, int> par = make_pair(i, j);
		m.insert({dis, par});
	   }	
	}
	for(auto it = m.begin(); it !=m.end(); it++) {
	   vec.push_back({it->second.first, it->second.second});
	}
	return vec;
    }
};

