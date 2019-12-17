class Solution 
{
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        string map[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."} ;
        unordered_set <string> set ;
        for(string s : words)
        {
            string str ;
            for(char c : s)
            {
                str += map[c - 'a'] ;
            }
            set.insert(str) ;
        }
        return set.size() ;
    }
};
