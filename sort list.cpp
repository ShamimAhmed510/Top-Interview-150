class Solution {
public:
    ListNode* sortList(ListNode* head) {
        for (ListNode* i = head; i != nullptr; i = i->next) {
            for (ListNode* j = i->next; j != nullptr; j = j->next) {
                if (i->val > j->val) {
                    swap(i->val, j->val);
                }
            }
        }

        return head;
    }
};
