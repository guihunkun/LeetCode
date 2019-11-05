class Solution 
{
public:
    string decodeString(string s) 
    {
        stack<int> numbers;
        int numberBegin = -1;
        stack<string> decoded;
        decoded.push("");
        for(int i = 0; i < s.length(); ++i) 
        {
            if(s[i] >= '0' && s[i] <= '9' && numberBegin == -1) 
            {
                numberBegin = i;
            } 
            else if(s[i] == '[') 
            {
                numbers.push(std::stoi(s.substr(numberBegin, i - numberBegin)));
                numberBegin = -1;
                decoded.push("");
            } 
            else if(s[i] == ']') 
            {
                string decodedPart;
                decodedPart.reserve(decoded.top().size() * numbers.top());
                for (int j = 0; j < numbers.top(); ++j)
                    decodedPart += decoded.top();
                decoded.pop();
                numbers.pop();
                decoded.top() += decodedPart;
            } 
            else if(numberBegin == -1) 
            {
                decoded.top() += s[i];
            }
        }
        return decoded.top();
    }
};
