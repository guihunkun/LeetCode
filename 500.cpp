class Solution 
{
public:
    vector<string> findWords(vector<string>& words) 
    {
        string row[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> output;
        for (auto word : words)
        {
            char first = tolower(word[0]);
            int rowindex = 0;
            for (int i=0;i<3;i++)
                if (row[i].find(first)!=string::npos)
                    rowindex = i;
            
            //cout << "row index : " << rowindex << endl;
            bool flag = false;
            for (int i=1;i<word.size();i++)
            {
                
                if (row[rowindex].find(tolower(word[i]))== string::npos) 
                    flag = true;
                if (flag==true) 
                    break;
            }
            if (flag==false) 
                output.push_back(word);
        }
        return output;
    }
};
