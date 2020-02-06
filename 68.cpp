class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int n = words.size();
        vector<string> vec;
        int len = 0;
        for (int cur = 0; cur<n; cur++)
        {
            len += words[cur].length();
            if (!vec.empty()) len++;
            if (len <= maxWidth)
            {
                vec.push_back(words[cur]);
                // last line
                if (cur == n-1)
                {
                    string str;
                    for (auto x: vec)
                    {
                        if (str.empty()) str += x;
                        else str += " " + x;
                    }
                    str.insert(str.end(), maxWidth-str.length(), ' ');
                    ret.push_back(str);
                    break;
                }
                continue;
            }

            // now combine them
            int vec_size = vec.size();
            int word_size = 0;
            for (auto x: vec) word_size += x.length();
            int space_size = maxWidth - word_size;
            string str;
            if (1 == vec_size)
            {
                str = vec[0];
                str.insert(str.end(), space_size, ' ');
            }
            else
            {
                while(--vec_size>0)
                {
                    int use_space = 0;
                    use_space = space_size/vec_size;
                    if (space_size%vec_size) use_space++;
                    space_size -= use_space;
                    str += vec[0];
                    str.insert(str.end(), use_space, ' ');
                    vec.erase(vec.begin());
                }
                str += vec[0];
            }
            ret.push_back(str);

            vec.clear();
            vec.push_back(words[cur]);
            len = words[cur].length();

            // last line
            if (cur == n-1)
            {
                string str = words[cur];
                str.insert(str.end(), maxWidth-str.length(), ' ');
                ret.push_back(str);
                break;
            }
        }
        
        return ret;
    }
};

