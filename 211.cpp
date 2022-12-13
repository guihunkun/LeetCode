#include<string>
using namespace std;
class WordDictionary {
public:
    struct Node
    {
        char c;
        bool val;
        Node *left;
        Node *mid;
        Node *right;
        Node() : val(false), left(nullptr), mid(nullptr), right(nullptr){}
    };

    Node *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = nullptr;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        root = addWord(root,word,0);
    }
    Node* addWord(Node* x,string word,int d){
        char c = word[d];
        if(x == nullptr){
            x = new Node();
            x->c = c;
        }
        if(c < x->c){
            x->left = addWord(x->left,word,d);
        }else if(c > x->c){
            x->right = addWord(x->right,word,d);
        }else if(d < word.length() - 1){
            x->mid = addWord(x->mid, word, d + 1);
        }else{
            x->val = true;
        }
        return x;
    }


    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Node *x = search(root,word,0);
        if(x == nullptr)
            return false;
        return x->val;
    }
    Node* search(Node* x,string word,int d){
        if(x == nullptr)
            return nullptr;
        char c = word[d];
        if(c == '.'){
            //在三个分支当中进行搜索

            if(d == word.length()-1)
                return x;
                
            Node *temp1 = search(x->mid, word, d+1);
            if(temp1!=nullptr&&temp1->val == true)
                return temp1;
            else{
                temp1 = search(x->left, word, d);
                if(temp1 != nullptr&&temp1->val == true){
                    return temp1;
                }else{
                    return  search(x->right,word,d);
                }
            }

        }else{
            if(c < x->c){
                return search(x->left, word, d);
            }else if(c > x->c){
                return search(x->right,word,d);
            }else if(d < word.length() - 1){
                return search(x->mid,word,d+1);
            }else{
                return x;
            }
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

