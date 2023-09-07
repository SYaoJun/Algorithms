class LRUCache {
public:
    struct Node{
         int key, val;
         Node* next, *prev;
         Node(int k, int v): key(k),val(v),next(nullptr), prev(nullptr){}
    }*L, *R;
    unordered_map<int, Node*> mp;
    int n;
    // 哈希表
    // 双向链表
    LRUCache(int cap) {
        n = cap;
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        L->next = R;
        R->prev = L;
    }
    
    int get(int key) {
        if(mp.count(key)) {
            Node *node = mp[key];
            remove(node);
            insert(node->key, node->val);
            return node->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int val) {
        if(mp.count(key)) {
            Node *node = mp[key];
            remove(node);
            insert(key, val);
        }else{
            if(mp.size() == n) {
                Node* node = L->next;
                remove(node);
                insert(key, val);
            }else{
                insert(key, val);
            }
        }
    }
    void remove(Node* node){
        auto pre = node->prev;
        auto nxt = node->next;
        
        pre->next = nxt;
        nxt->prev = pre;
        mp.erase(node->key);
    }
    void insert(int key, int val) {
        auto pre = R->prev;
        auto nxt = R;
        auto node = new Node(key, val);
        
        pre->next = node;
        node->next = nxt;
        
        nxt->prev = node;
        node->prev = pre;
        mp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */