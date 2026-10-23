
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) return 0;

        unordered_set<string> valid(bank.begin(), bank.end());

        if (valid.find(endGene) == valid.end()) {
            return -1;
        }

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({startGene, 0});
        visited.insert(startGene);

        while (!q.empty()) {
            string current = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (string gene : bank) {
                if (visited.count(gene)) continue;

                int diff = 0;

                for (int i = 0; i < 8; i++) {
                    if (current[i] != gene[i]) {
                        diff++;
                    }
                }

                if (diff == 1) {
                    if (gene == endGene) {
                        return steps + 1;
                    }

                    visited.insert(gene);
                    q.push({gene, steps + 1});
                }
            }
        }

        return -1;
    }
};
