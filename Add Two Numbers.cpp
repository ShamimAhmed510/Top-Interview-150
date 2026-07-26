// https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a, b;
        
        while (l1) {
            a.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            b.push_back(l2->val);
            l2 = l2->next;
        }

        vector<int> ans;
        int i = 0, j = 0, carry = 0;
        
        while (i < a.size() || j < b.size() || carry > 0) {
            int sum = carry;
            if (i < a.size()) sum += a[i++];
            if (j < b.size()) sum += b[j++];
            
            ans.push_back(sum % 10);
            carry = sum / 10;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int val : ans) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
