//https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (string s : strs) {

            string key = s;                 // original string copy
            sort(key.begin(), key.end());   // sort copy

            mp[key].push_back(s);           // original string store
        }

        vector<vector<string>> ans;

        for (auto x : mp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};
