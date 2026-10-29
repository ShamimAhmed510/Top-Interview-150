class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }

    Node* solve(vector<vector<int>>& grid, int r, int c, int len) {
        int value = grid[r][c];
        bool same = true;

        for (int i = r; i < r + len; i++) {
            for (int j = c; j < c + len; j++) {
                if (grid[i][j] != value) {
                    same = false;
                    break;
                }
            }

            if (!same) break;
        }

        if (same) {
            return new Node(value == 1, true);
        }

        int half = len / 2;
        Node* root = new Node(false, false);

        root->topLeft = solve(grid, r, c, half);
        root->topRight = solve(grid, r, c + half, half);
        root->bottomLeft = solve(grid, r + half, c, half);
        root->bottomRight = solve(grid, r + half, c + half, half);

        return root;
    }
};
