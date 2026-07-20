#include <bits/stdc++.h>
// https://leetcode.com/problems/simplify-path/description/?envType=study-plan-v2&envId=top-interview-150
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<string> st;

    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '/') continue;

        string temp = "";
        while (i < n && s[i] != '/')
        {
            temp += s[i];
            i++;
        }

        if (temp == ".")
        {
            continue;
        }
        else if (temp == "..")
        {
            if (!st.empty())
            {
                st.pop_back();
            }
        }
        else
        {
            st.push_back(temp);
        }
    }

    string res = "";

    for (string u : st)
    {
        res += "/" + u;
    }

    if (res.empty())
    {
        cout << "Simplified s: /" << endl;
    }
    else
    {
        cout << "Simplified s: " << res << endl;
    }

    return 0;
}
