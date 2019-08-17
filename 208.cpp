class Trie 
{
    map<char, Trie*> children;
    bool wordEndHere;
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        wordEndHere = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Trie *curr = this;
        for( auto s : word )
        {
            if( curr->children.find(s) == curr->children.end() )
                curr->children[s] = new Trie();
            curr = curr->children[s];
        }
        curr->wordEndHere = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Trie *curr = this;
        for( auto s : word ) 
        {
            if( curr->children.find(s) == curr->children.end() )
                return false;
            curr = curr->children[s];
        }
        return curr->wordEndHere;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Trie *curr = this;
        for( auto s : prefix )
        {
            if( curr->children.find(s) == curr->children.end() )
                return false;
            curr = curr->children[s];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
