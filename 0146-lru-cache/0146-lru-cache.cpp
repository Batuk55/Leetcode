class Node {
public:
    int key, value;
    Node* next;
    Node* prev;

    Node(int x, int y) {
        key = x;
        value = y;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mpp;
    int capacity;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        mpp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void insert_after_head(Node* node) { // insert_after_head
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }
    void dereference_node(Node* node) { // dereference_node
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        
        dereference_node(node);
        insert_after_head(node);

        return node->value;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->value = value;

            dereference_node(node);
            insert_after_head(node);

        } else {
            if (mpp.size() >= capacity) {
                // mpp.delete(tail->prev->key);

                Node* temp = tail->prev;
                mpp.erase(temp->key);

                dereference_node(temp);
                delete temp;
            }

            Node* node = new Node(key, value);
            mpp[key] = node;
            insert_after_head(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */