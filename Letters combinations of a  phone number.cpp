
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> v = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans = {""};

        for (char digit : digits) {
            int num = digit - '0';
            vector<string> temp;

            for (string x : ans) {
                for (char ch : v[num]) {
                    temp.push_back(x + ch);
                }
            }

            ans = temp;
        }

        return ans;
    }
};
