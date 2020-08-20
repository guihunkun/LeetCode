class Solution 
{
public:
	bool IsDigital(char numChr) 
	{
		if(numChr > '0' && numChr <= '9') 
        {
			return true;
		}
		return false;
	}
    string decodeAtIndex(string S, int K) 
    {
		if(S.empty()) 
        {
			return "";
		}
		long long currentStrLength = 0;
		int index = 0;
		for(; index < S.length(); index++) 
        {
			if(IsDigital(S[index])) 
            {
				currentStrLength *= (S[index] - '0');
			} 
            else 
            {
				currentStrLength++;
			}
			if(currentStrLength >= K) 
            {
				break;
			}
		}
		for(int j = index; j >= 0; j--) 
        {
			if(IsDigital(S[j])) 
            {
				currentStrLength = currentStrLength / (S[j] - '0');
				K = K % currentStrLength;
			} 
            else 
            {
				if(K % currentStrLength == 0) 
                {
					return string(1, S[j]);
				}
				currentStrLength--;
			}
		}
        return "";
    }
};
