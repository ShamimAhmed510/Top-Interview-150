
class Trie {
private:
    set<string> words;

public:
    Trie() {}

    void insert(string word) {
        words.insert(word);
    }

    bool search(string word) {
        return words.find(word) != words.end();
    }

    bool startsWith(string prefix) {
        for (string word : words) {
            if (word.find(prefix) == 0) {
                return true;
            }
        }

        return false;
    }
};
