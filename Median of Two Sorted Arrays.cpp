class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x : nums1) {
            pq.push(x);
        }

        for (int x : nums2) {
            pq.push(x);
        }

        int n = nums1.size() + nums2.size();

        int mid = n / 2;

        int a = 0, b = 0;

        for (int i = 0; i <= mid; i++) {

            a = b;
            b = pq.top();
            pq.pop();
        }

        if (n % 2 == 1) {
            return b;
        }

        return ((double)a + b) / 2.0;
    }
};
