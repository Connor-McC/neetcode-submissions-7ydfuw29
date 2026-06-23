class LRUCache {
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> map;
    Node* head; // LRU end
    Node* tail; // MRU end

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtTail(Node* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0); // dummy LRU sentinel
        tail = new Node(0, 0); // dummy MRU sentinel
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!map.count(key)) return -1;
        Node* node = map[key];
        remove(node);
        insertAtTail(node);
        return node->val;
    }

    void put(int key, int val) {
        if (map.count(key)) {
            remove(map[key]);
            delete map[key];
        } else if (map.size() == capacity) {
            Node* lru = head->next;
            map.erase(lru->key);
            remove(lru);
            delete lru;
        }
        Node* node = new Node(key, val);
        map[key] = node;
        insertAtTail(node);
    }
};
