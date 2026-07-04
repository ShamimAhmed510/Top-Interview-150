//https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int word_len = words[0].size();
        int word_count = words.size();
        int total_len = word_len * word_count;
        int s_len = s.size();

        if (s_len < total_len) return result;

        unordered_map<string, int> word_freq;
        for (const string& w : words) {
            word_freq[w]++;
        }

        for (int i = 0; i < word_len; i++) {
            int left = i, right = i;
            int count = 0;
            unordered_map<string, int> seen_words;

            while (right + word_len <= s_len) {
                string word = s.substr(right, word_len);
                right += word_len;

                if (word_freq.count(word)) {
                    seen_words[word]++;
                    count++;

                    while (seen_words[word] > word_freq[word]) {
                        string left_word = s.substr(left, word_len);
                        seen_words[left_word]--;
                        count--;
                        left += word_len;
                    }

                    if (count == word_count) {
                        result.push_back(left);
                    }
                } else {
                    seen_words.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
