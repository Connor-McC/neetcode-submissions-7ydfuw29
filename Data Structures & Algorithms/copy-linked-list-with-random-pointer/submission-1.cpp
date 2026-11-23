/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* n1 = head;
        while (n1 != nullptr){
            Node* n2 = new Node(n1->val);
            n2->next = n1->next;
            n1->next = n2;
            n1 = n2->next;
        }

        Node* newHead = head->next;
        n1 = head;
        while (n1 != nullptr){
            if (n1->random != nullptr) n1->next->random = n1->random->next;
            n1 = n1->next->next;
        }

        n1 = head;
        while (n1 != nullptr){
            Node* n2 = n1->next;
            n1->next = n2->next;
            if (n2->next != nullptr) n2->next = n2->next->next;
            n1 = n1->next;
        }
        return newHead;
    }
};
