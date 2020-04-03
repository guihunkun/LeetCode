class Trie{
private:
    bool is_string;
    Trie *next[26];
public:
    Trie(){
        is_string=false;
        memset(next,0,sizeof(next));
    }
    
    void insert(string word){
        Trie *root=this;
        for(const auto& w:word){
            if(root->next[w-'a']==nullptr)root->next[w-'a']=new Trie();
            root=root->next[w-'a'];
        }
        root->is_string=true;
    }
    
    bool search(string word,int index,int count){
        Trie *root=this;//每次从根节点开始寻找
        for(int i=index;i<word.size();++i){
            if(root->next[word[i]-'a']==nullptr)return false;//word的某个字符不在前缀树中
            root=root->next[word[i]-'a'];
            if(root->is_string){//到达某个单词尾
                if(i==word.size()-1)return count>=1;//count的数量至少为2个，若遍历到最后只有一个单词，则count的值还是为0
                //已前count位的单词作为分解词继续匹配下一个单词,下个单词满足count才能返回ture,否则继续寻找下一个分界单词
                if(search(word,i+1,count+1))return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie *root=new Trie();
        for(const auto &word:words){
            root->insert(word);
        }
        vector<string> result;
        for(const auto &word:words){
            if(root->search(word,0,0))
                result.push_back(word);
        }
        return result;
    }
};
