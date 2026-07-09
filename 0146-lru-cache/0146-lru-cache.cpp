class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };
    unordered_map<int, Node*> cache;
    int cap = 0;
    Node* head, *tail;
    
    //if we have to insert a node immediately after a head, which will make is most recently used node
    void addToFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(Node* node){
        Node* left = node->prev;
        Node* right = node->next;
        left->next = right;
        right->prev = left;
    }
    void moveToFront(Node* node){
        removeNode(node);
        addToFront(node);
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        //dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;

    }
    
    int get(int key) {
      if(cache.find(key) == cache.end()){
        return -1;
      }
      Node* node = cache[key];
      moveToFront(node);
      return node->value;
    }
    
    void put(int key, int value) {
        //case 1 key already exists, update the value and move to front
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
            return;
        }
        //cache full -> remove lru
        if(cache.size()==cap){
            Node* node = tail->prev;
            cache.erase(node->key);
            removeNode(node);
            delete node;
        }
        //create new node
        Node* node = new Node(key, value);
        cache[key] = node;
        addToFront(node);

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */