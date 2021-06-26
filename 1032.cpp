class StreamChecker 
{
    struct trieNode 
    {
        trieNode *children[26];
        bool completeword =false; 
    };
    typedef struct trieNode tnode;
    int maxwsz; 
    tnode *root;
    list<char> qst; 
public:
    tnode* getNode()
    {
        tnode* nnd = new tnode();
        for(int i=0; i<25; i++) {
            nnd->children[i]=0;
        }
        return nnd;
    }
    void insert(string s, tnode* troot)
    {
        for(int i= s.size()-1; i>=0; i--)
        {
            if(!troot->children[s[i]-'a']) {
                troot->children[s[i]-'a'] = getNode();
            }
            troot = troot->children[s[i]-'a'];
        }
        troot->completeword = true; 
    }
    StreamChecker(vector<string>& words) {
       //create the db 
        maxwsz = 0;
        root = getNode();
       for(int i=0; i<words.size(); ++i)  
       {
           insert(words[i],root);
           if(maxwsz<words[i].size())
               maxwsz= words[i].size();
       }
        //cout<<"done constructing"<<endl;
    }
    bool searchString(tnode* troot)
    {
        list<char>::iterator it = qst.end();
        it--;
        for(int i = 0; i<qst.size();--it,++i)
        {
            if(troot->children[*it-'a']==0)
                return false; 
            troot = troot->children[*it-'a'];
            if(troot->completeword)
                return true;
        }
        return troot->completeword;
    }
    
    bool query(char letter) 
    {
        if(qst.size() >=maxwsz ) {
            qst.erase(qst.begin());
        }
        qst.push_back(letter);
        if(searchString(root)) 
           return true; 
        return false; 
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
