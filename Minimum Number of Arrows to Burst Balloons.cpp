// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
       
        sort(v.begin(), v.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int ans = 1;
        int last_pos = v[0][1];

        for (int i = 1; i < v.size(); i++) {
            if(v[i][0] > last_pos)
            {
                ans++;
                last_pos=v[i][1];
            }
        }
        return ans;
    }
};
