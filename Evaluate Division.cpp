class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;

    double dfs(string src, string dest,
               unordered_set<string>& vis) {
        if (!adj.count(src) || !adj.count(dest))
            return -1.0;

        if (src == dest)
            return 1.0;

        vis.insert(src);

        for (auto [next, val] : adj[src]) {
            if (vis.count(next))
                continue;

            double ans = dfs(next, dest, vis);

            if (ans != -1.0)
                return val * ans;
        }

        return -1.0;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;

        for (auto& q : queries) {
            unordered_set<string> vis;
            ans.push_back(dfs(q[0], q[1], vis));
        }

        return ans;
    }
};
