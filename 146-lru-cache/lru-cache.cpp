class LRUCache {
private:
    int current_size;
    int n;
    
public:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };
    
    unordered_map<int, Node*> ump;
    Node* head;
    Node* tail;
    
    LRUCache(int capacity) {
        current_size = 0;
        n = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->next = NULL;

        tail->prev = head;
        head->prev = NULL;
    }
    
    // Optional but good practice: Destructor to clean up memory
    ~LRUCache() {
        Node* curr = head;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    void pbh(Node* head, Node* tail, Node* curr) {
        Node* front = head->next;
        head->next = curr;
        curr->next = front;
        front->prev = curr;
        curr->prev = head;
    }
    
    void dfb(Node* head, Node* tail) {
        Node* lru = tail->prev;
        Node* new_lru = lru->prev;
        new_lru->next = tail;
        tail->prev = new_lru;
        delete(lru);
    }
    
    void rfp(Node* head, Node* tail, Node* curr) {
        Node* left = curr->prev;
        Node* right = curr->next;
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (ump.find(key) != ump.end()) {
            Node* curr = ump[key];
            // remove from its current position
            rfp(head, tail, curr);    
            // add to head
            pbh(head, tail, curr);
            return ump[key]->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // Case 1: Key already exists
        if (ump.find(key) != ump.end()) {
            ump[key]->val = value;
            Node* curr = ump[key];
            rfp(head, tail, curr);
            pbh(head, tail, curr);
            return; // We are done, exit early
        }
        
        // Case 2: Key doesn't exist, and cache is FULL
        if (current_size == n) {
            // Get the LRU key before deleting the node
            int lru_key = tail->prev->key; 
            
            // Delete from map FIRST, using the LRU key
            ump.erase(lru_key); 
            
            // Now delete from the linked list
            dfb(head, tail); 
        } else {
            // Case 3: Key doesn't exist, and we have room
            current_size++;
        }
        
        // Add the new node to the map and linked list
        Node* curr = new Node(key, value);
        ump[key] = curr;
        pbh(head, tail, curr);
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */