#include "../header.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* f = dummy;
        
        n++;
        while (n--) {
            f = f->next;
        }
        
        while (f != nullptr) {
            f = f->next;
            p = p->next;
        }
        ListNode* tmp = p->next;
        p->next = tmp->next;
        delete tmp;

        return dummy->next;
    }
};