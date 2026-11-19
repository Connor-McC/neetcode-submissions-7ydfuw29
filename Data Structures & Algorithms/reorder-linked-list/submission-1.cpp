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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* sec = slow->next;
        ListNode* prev = slow->next = nullptr;
        while (sec != nullptr){
            ListNode* temp = sec->next;
            sec->next = prev;
            prev = sec;
            sec = temp;
        }

        ListNode* fir = head;
        sec = prev;
        while (sec != nullptr){
            ListNode* tmp1 = fir->next;
            ListNode* tmp2 = sec->next;

            fir->next = sec;
            sec->next = tmp1;
            fir = tmp1;
            sec = tmp2;
        }

    }
};
