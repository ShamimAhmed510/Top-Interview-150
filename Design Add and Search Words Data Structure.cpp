class WordDictionary {
    struct Node {
        Node* child[26] = {};
        bool isEnd = false;
    };

    Node* root;

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* cur = root;

        for (char c : word) {
            int i = c - 'a';

            if (cur->child[i] == nullptr) {
                cur->child[i] = new Node();
            }

            cur = cur->child[i];
        }

        cur->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(Node* cur, string& word, int pos) {
        if (pos == word.size()) {
            return cur->isEnd;
        }

        if (word[pos] == '.') {
            for (int i = 0; i < 26; i++) {
                if (cur->child[i] != nullptr &&
                    dfs(cur->child[i], word, pos + 1)) {
                    return true;
                }
            }
            return false;
        }

        int i = word[pos] - 'a';

        if (cur->child[i] == nullptr) {
            return false;
        }

        return dfs(cur->child[i], word, pos + 1);
    }
};
