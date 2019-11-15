struct Node{
    int val;
    Node *next;
    Node(int val): val(val),next(nullptr){}
};
const int len = 100;
class MyHashSet {
    
public:
    vector<Node*> arr; 
    /** Initialize your data structure here. */
    MyHashSet() {
        arr = vector<Node*>(len, new Node(-1));
    }
    
    void add(int key) {
        int haval = key % len;
        Node* temp = arr[haval];
        if(temp -> val != -1){
            while(temp){
                if(temp -> val == key)  return;
                if(!(temp -> next)){
                    Node *node = new Node(key);
                    temp -> next = node;
                    return;
                }
                temp = temp -> next;
            }
        }
        else{
            temp -> val = key;
            return;
        }
    }
    
    void remove(int key) {
        int haval = key % len;
        Node* temp = arr[haval];
        if(temp -> val != -1){
            while(temp){
                if(temp -> val == key){
                    temp -> val = -1;
                    return;
                }
                temp = temp -> next;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int haval = key % len;
        Node* temp = arr[haval];
            while(temp){
                if(temp -> val == key)    return true;
                temp = temp -> next;
            }
        return false;
    }
};
