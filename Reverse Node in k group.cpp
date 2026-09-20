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
private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 1) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;

        while (true) {
            ListNode* kth = getKthNode(prevGroup->next, k);
            if (!kth) break; 

            ListNode* nextGroup = kth->next;
            ListNode* curr = prevGroup->next;
            ListNode* prev = nextGroup;

            while (curr != nextGroup) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = temp;
        }

        return dummy.next;
    }
};
