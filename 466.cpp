class Solution 
{
public:
int getMaxRepetitions(std::string s1, int n1, std::string s2, int n2) 
{
	std::vector<int> v;
	std::unordered_map<int, int> m; //the value of num
	int s = 0;
	int len = s1.size(),len2=s2.size();
	int i = 0;
	for(i = 0; i < n1; i++) 
    {
		int sr = s;
		auto pfind = m.find(s);
		if(pfind != m.end()) 
            break;
		int r = 0;
		for(int j = 0; j < len; j++) 
        {
			if(s2[s] == s1[j]) 
            {
				s++;
				if(s == len2) 
                {
					r++;
					s = 0;
				}
			}
		}
		m[sr] = i;
		v.push_back(r);
	}
	//to statis
	int sum = 0;
	int loopLen = 0;
	if(i == n1)
        loopLen = 0;
	else 
    {
		loopLen = i-m[s];
	}
	int hLen = i - loopLen;
	//to add head
	for(int j = 0; j < hLen; j++) 
    {
		sum += v[j];
	}
	int loopSum = 0;
	for(int j = 0; j < loopLen; j++) 
    {
		loopSum += v[hLen+j];
	}
	//to add loop
	if(loopLen!=0)
		sum += ((n1 - hLen) / loopLen)* loopSum;
	int less = 0;
	if(loopLen != 0)
		less = (n1 - hLen) % loopLen;
	else
		less = n1 - hLen;
	//to add end
	for(int j = 0; j < less; j++) 
    {
		sum += v[hLen+j];
	}
	return sum / n2;
}
};

