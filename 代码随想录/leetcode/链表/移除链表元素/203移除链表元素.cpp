#include "../header.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* p = dummy;
        while (p->next != nullptr) {
            if (p->next->val == val) {
                ListNode* tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            } else {
                p = p->next;
            }
        }
        return dummy->next;
    }
};