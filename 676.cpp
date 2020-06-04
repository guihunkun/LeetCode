struct TrieNode
{
    bool end;
    unordered_map<char, TrieNode*> map;

    TrieNode() : end(false) {}
};


class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

        m_root = new TrieNode;
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (int i = 0; i < dict.size(); ++i)
        {
            insert(dict.at(i));
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {

        int res = false;
        for (int i = 0; i < word.size(); ++i)
        {
            dfs(m_root, word, i, 0, res);
            if (res)
            {
                return true;
            }
        }

        return false;
    }


private:
    void insert(const string& word)
    {
        if(word.empty())
        {
            return;
        }

        TrieNode* cur = m_root;

        for (int i = 0; i < word.size(); ++i)
        {
            auto iter = cur->map.find(word.at(i));
            if (iter == cur->map.end())
            {
                cur->map[word.at(i)] = new TrieNode;
            }
            cur = cur->map[word.at(i)];
        }

        cur->end = true;
    }

    void dfs(TrieNode* node, string& word, int index_change, int index, int& res)
    {
        if (index == word.size())
        {
            if (node->end)
            {
                res = true;
            }

            return;
        }

        if (index == index_change) //当前索引是要被改变处
        {
            //找除当前字符外的其他字符路径
            for (const auto& p : node->map)
            {
                if (p.first != word.at(index))
                {
                    dfs(p.second, word, index_change, index + 1, res);
                }
            }
        }
        else
        {
            auto iter = node->map.find(word.at(index));
            if (iter != node->map.end())
            {
                dfs(iter->second, word, index_change, index + 1, res);
            }
        }
    }

private:
    TrieNode* m_root;
};
/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
