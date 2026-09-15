class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long ans = 0;
        long long num = 0;
        long long sign = 1;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)){
                num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                ans += num * sign;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            } else if (c == ')') {
                ans *= st.top();
                st.pop();
                ans += st.top();
                st.pop();
            }
        }

        return int(ans);
    }
};
