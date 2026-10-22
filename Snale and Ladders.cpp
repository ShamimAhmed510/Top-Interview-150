
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;

        queue<pair<int, int>> q;
        vector<bool> visited(target + 1, false);

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            if (curr == target) {
                return moves;
            }

            for (int next = curr + 1; next <= min(curr + 6, target); next++) {

                int r = (next - 1) / n;
                int c = (next - 1) % n;

                int row = n - 1 - r;

                if (r % 2 == 1) {
                    c = n - 1 - c;
                }

                int dest = next;

                if (board[row][c] != -1) {
                    dest = board[row][c];
                }

                if (!visited[dest]) {
                    visited[dest] = true;
                    q.push({dest, moves + 1});
                }
            }
        }

        return -1;
    }
};
