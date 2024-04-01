#include "../header.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* s = dummy->next;
        ListNode* f = s->next;
        while (f != nullptr) {
            ListNode* tmp = f->next;
            
            p->next = f;
            f->next = s;
            s->next = nullptr;

            p = s;
            s = tmp;
            p->next = tmp;
            if (s != nullptr) {
                f = s->next;
            } else {
                f = nullptr;
            }
        }
        
        
        return dummy->next;
    }
};