
class Solution {
public:
    struct Node {
        Node* next[26] = {};
        string word = "";
    };

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& b, int i, int j, Node* p,
             vector<string>& ans) {

        char c = b[i][j];

        if (!p->next[c - 'a'])
            return;

        p = p->next[c - 'a'];

        if (p->word != "") {
            ans.push_back(p->word);
            p->word = "";
        }

        b[i][j] = '#';

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && y >= 0 && x < b.size() && y < b[0].size() &&
                b[x][y] != '#') {
                dfs(b, x, y, p, ans);
            }
        }

        b[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        Node* root = new Node();

        for (string w : words) {
            Node* p = root;

            for (char c : w) {
                if (!p->next[c - 'a'])
                    p->next[c - 'a'] = new Node();

                p = p->next[c - 'a'];
            }

            p->word = w;
        }

        vector<string> ans;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};
