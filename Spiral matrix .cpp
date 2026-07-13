class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if (matrix.empty()) return v;

        int m = matrix.size();    // Rows
        int n = matrix[0].size(); // Columns

        // Initialize the 4 boundaries
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            
            // 1. Move from left to right (Top Row)
            for (int j = left; j <= right; ++j) {
                v.push_back(matrix[top][j]);
            }
            top++; // Shift top boundary downwards

            // 2. Move from top to bottom (Right Column)
            for (int i = top; i <= bottom; ++i) {
                v.push_back(matrix[i][right]);
            }
            right--; // Shift right boundary leftwards

            // 3. Move from right to left (Bottom Row)
            // Condition check to handle single row remaining
            if (top <= bottom) {
                for (int j = right; j >= left; --j) {
                    v.push_back(matrix[bottom][j]);
                }
                bottom--; // Shift bottom boundary upwards
            }

            // 4. Move from bottom to top (Left Column)
            // Condition check to handle single column remaining
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    v.push_back(matrix[i][left]);
                }
                left++; // Shift left boundary rightwards
            }
        }

        return v;
    }
};
