//https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> b;
        int n = v.size();

        sort(v.begin(), v.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && v[i] == v[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = v[i] + v[left] + v[right];

                if (sum == 0) {
                    b.push_back({v[i], v[left], v[right]});
                    while (left < right && v[left] == v[left + 1])
                        left++;
                    while (left < right && v[right] == v[right - 1])
                        right--;
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++; 
                } else {
                    right--; 
                }
            }
        }
        return b;
    }
};
