class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) return s;

        vector<string> v(n);
        int l = 0;

        while (l < s.size()) {

            for (int i = 0; i < n && l < s.size(); i++) {
                v[i] += s[l++];
            }

            for (int i = n - 2; i > 0 && l < s.size(); i--) {
                v[i] += s[l++];
            }
        }

        string ans = "";

        for (int i = 0; i < n; i++) {
            ans += v[i];
        }

        return ans;
    }
};
