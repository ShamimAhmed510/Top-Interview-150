
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> tails;

        for(int i = 0; i < nums.size(); i++) {

            int l = 0;
            int r = tails.size() - 1;

            while(l <= r) {

                int mid = l + (r - l) / 2;

                if(tails[mid] >= nums[i]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }

            if(l == tails.size()) {
                tails.push_back(nums[i]);
            }
            else {
                tails[l] = nums[i];
            }
        }

        return tails.size();
    }
};
