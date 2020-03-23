struct DLNode {
    int freq;
    DLNode* prev;
    DLNode* next;
    DLNode() : freq(0), prev(nullptr), next(nullptr) {}
    DLNode(int f) : freq(f), prev(nullptr), next(nullptr) {}
};
struct DLList {
    DLNode* head;
    DLNode* tail;
    DLList() {
        head = new DLNode();
        tail = new DLNode();
        head->next = tail;
        tail->prev = head;
    }
    void erase(DLNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete node;
    }
    void add(DLNode* left, DLNode* right, DLNode* node) {
        left->next = node;
        right->prev = node;
        node->prev = left;
        node->next = right;
    }
    int getMaxFreq() {
        return tail->prev->freq;
    }
    int getMinFreq() {
        return head->next->freq;
    }
};

class AllOne {
public:
    DLList* dl;
    unordered_map<string, int> value_freq;
    unordered_map<string, int> value_index;
    unordered_map<int, vector<string> > freq_values;
    unordered_map<int, DLNode*> freq_node;

    void incrKey(const string& key) {
        if (value_freq.count(key) == 0) {
            value_freq[key] = 1;
            freq_values[1].push_back(key);
            value_index[key] = freq_values[1].size() - 1;
        } else {
            // remove old info
            int freq = value_freq[key];
            int ind = value_index[key];
            string tail_key = freq_values[freq].back();
            freq_values[freq][ind] = tail_key;
            freq_values[freq].pop_back();
            if (tail_key != key) {
                value_index[tail_key] = ind;
            }
            // add new info
            ++value_freq[key];
            ++freq;
            freq_values[freq].push_back(key);
            value_index[key] = freq_values[freq].size() - 1;
        }
    }
    void decrKey(const string& key) {
        if (value_freq.count(key) == 0) return;
        int freq = value_freq[key];
        int ind = value_index[key];
        // remove old info
        string tail_key = freq_values[freq].back();
        freq_values[freq][ind] = freq_values[freq].back();
        freq_values[freq].pop_back();
        if (tail_key != key) {
            value_index[tail_key] = ind;
        }
        // update info
        --freq;
        if (freq == 0) {
            value_freq.erase(key);
            value_index.erase(key);
        } else {
            value_freq[key] = freq;
            freq_values[freq].push_back(key);
            value_index[key] = freq_values[freq].size() - 1;
        }
    }
    void incrFreq(int old_freq) {
        int new_freq = old_freq + 1;
        auto left = freq_node[old_freq];
        auto right = left->next;
        if (freq_node.count(new_freq) == 0) {
            auto node = new DLNode(new_freq);
            freq_node[new_freq] = node;
            dl->add(left, right, node);
        }
        if (old_freq != 0 && freq_values[old_freq].empty()) {
            dl->erase(left);
            freq_node.erase(old_freq);
        }
    }
    void decrFreq(int old_freq) {
        int new_freq = old_freq - 1;
        auto right = freq_node[old_freq];
        auto left = right->prev;
        if (freq_node.count(new_freq) == 0) {
            auto node = new DLNode(new_freq);
            freq_node[new_freq] = node;
            dl->add(left, right, node);
        }
        if (old_freq != 0 && freq_values[old_freq].empty()) {
            dl->erase(right);
            freq_node.erase(old_freq);
        }
    }
    string getValueofFreq(int freq) {
        if (freq == 0 || freq_values[freq].empty()) return "";
        int s = freq_values[freq].size();
        int r = rand() % s;
        return freq_values[freq][r];
    }
    /** Initialize your data structure here. */
    AllOne() {
        dl = new DLList();
        freq_node[0] = dl->head;
    }
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        int old_freq = value_freq.count(key) ? value_freq[key] : 0;
        incrKey(key);
        incrFreq(old_freq);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (value_freq.count(key) == 0) return;
        int old_freq = value_freq[key];
        decrKey(key);
        decrFreq(old_freq);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return getValueofFreq(dl->getMaxFreq());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return getValueofFreq(dl->getMinFreq());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
