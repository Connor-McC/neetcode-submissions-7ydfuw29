class MinStack {
    private:
    struct Node {
        int val;
        int min;
        Node* next;
        Node(int v, int m, Node* n) : val(v), min(m), next(n) {}
    };
    Node* head = nullptr;
public:
    MinStack() {}

    ~MinStack() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    
    void push(int val) {
        int newMin = head ? std::min(val, head->min) : val;
        head = new Node(val, newMin, head);
    }
    
    void pop() {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};
