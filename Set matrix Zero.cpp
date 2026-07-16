#include <bits/stdc++.h>


using namespace std;

void setZeroes(vector<vector<int>>& v) {
    int n = v.size();
    int m = v[0].size();

    vector<bool> Row(n, false);
    vector<bool> Col(m, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                Row[i] = true;
                Col[j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Row[i] || Col[j]) {
                v[i][j] = 0;
            }
        }
    }
}

void printMatrix(const vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 1, 0}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    cout << "-----------------" << endl;

    setZeroes(matrix);

    cout << "Modified Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}
