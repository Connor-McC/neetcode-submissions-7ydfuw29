/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if there are k nodes remaining
        ListNode* node = head;
        for (int i = 0; i < k; i++) {
            if (node == nullptr) return head; // fewer than k nodes, leave as-is
            node = node->next;
        }
        // 'node' is now the head of the next group

        // Reverse k nodes starting from head
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // 'prev' is the new head of this group
        // 'head' is now the tail of this group, connect it to the next group
        head->next = reverseKGroup(node, k);

        return prev;
    }
};
