class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto row : prerequisites) {
            int ai = row[0];
            int bi = row[1];

            adj[bi].push_back(ai);
            indegree[ai]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            for (int next : adj[course]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return count == numCourses;
    }
};
