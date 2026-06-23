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
        unordered_map<Node*, Node*> copies;

        // First pass: create a copy of every node
        Node* curr = head;
        while (curr != nullptr) {
            copies[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Second pass: wire up next and random pointers
        curr = head;
        while (curr != nullptr) {
            copies[curr]->next   = copies[curr->next];
            copies[curr]->random = copies[curr->random];
            curr = curr->next;
        }

        return copies[head];
    }
};