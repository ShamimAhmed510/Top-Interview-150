class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> nums;
        ListNode* temp = head;
        while (temp != nullptr) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        int l = left - 1, r = right - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }

        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->val = nums[i++];
            temp = temp->next;
        }

        return head;
    }
};
