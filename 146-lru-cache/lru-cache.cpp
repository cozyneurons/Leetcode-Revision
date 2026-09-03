class LRUCache {
public:
    int n;
    int curr;
    struct Node 
    {
        int key;
        int val;
        Node* next;
        Node* prev;
        
        // Constructor to easily create a new node
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = NULL;
            prev = NULL;
        }
    };
    Node* head;
    Node* tail;
    // Map stores the key, and a pointer (iterator) to the node in the list.
    unordered_map<int, Node*> ump;
    LRUCache(int capacity) 
    {
        n = capacity;
        curr = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) 
    {
        if (ump.find(key)==ump.end())
        {
            return -1;
        }
        Node* most_recent = ump[key];
        Node* piche = most_recent->prev;
        Node* aage = most_recent->next;
        piche->next = aage;
        aage->prev = piche;

        Node* front = head->next;
        most_recent->next = front;
        most_recent->prev = head;
        front->prev = most_recent;
        head->next = most_recent;
        return ump[key]->val;
    }
    
    void put(int key, int value) 
    {
        // agar map mei nahi hai toh add karna hai
        if (ump.find(key)==ump.end())
        {
            curr++;
            if (curr>n)
            {
                // agar cache ka size capacity se jyada ho raha hai toh remove least recently used node 
                Node* least_recent = tail->prev;
                Node* back = least_recent->prev;
                back->next = tail;
                tail->prev = back;
                ump.erase(least_recent->key);
                delete(least_recent);
                curr--;
            }
            Node* New = new Node(key,value);
            Node* front = head->next;
            New->next = front;
            New->prev = head;
            front->prev = New;
            head->next = New;
            ump[key] = New;
        }
        else
        {
            // just update
            ump[key]->val = value;
            // put this key in front because it is recently used
            Node* most_recent = ump[key];
            Node* piche = most_recent->prev;
            Node* aage = most_recent->next;
            piche->next = aage;
            aage->prev = piche;

            Node* front = head->next;
            most_recent->next = front;
            most_recent->prev = head;
            front->prev = most_recent;
            head->next = most_recent;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */