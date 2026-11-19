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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode blank(0, head);
        ListNode* forward = head;
        int gap = 0;
        while (n > 0){
            forward = forward->next;
            n--;
        }
        ListNode* back = &blank;
        while (forward != nullptr){
            forward = forward->next;
            back = back->next;
        }

        back->next = back->next->next;
        return blank.next;
    }
};
