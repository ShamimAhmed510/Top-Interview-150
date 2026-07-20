#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150

int main()
{
    int n;
    cin >> n;

    if (n <= 0)
    {
        cout << "No intervals to merge." << endl;
        return 0;
    }

    vector<vector<int>> v(n, vector<int>(2));
    
    cout << "Enter the intervals (start and end pairs):" << endl;
    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }

    
    sort(v.begin(), v.end());

    vector<vector<int>> ans;

    ans.push_back(v[0]);

    for (int i = 1; i < n; i++)
    {
        int start = v[i][0];
        int end   = v[i][1];

        if (start <= ans.back()[1])
        {
            ans.back()[1] = max(ans.back()[1], end);
        }
        else
        {
            ans.push_back({start, end});
        }
    }

    cout << "\nMerged Intervals: [";
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[" << ans[i][0] << "," << ans[i][1] << "]";
        if (i < ans.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
