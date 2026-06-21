// https://leetcode.com/problems/text-justification/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;          
        vector<string> current_line; 
        int current_len = 0;         
        
        int n = words.size();
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            cnt += words[i].size();
            
            if (cnt <= maxWidth) {
                current_line.push_back(words[i]);
                current_len += words[i].size();
                cnt++; 
            } 
            else {
                string line = "";
                int num_words = current_line.size();
                
                if (num_words == 1) {
                    line += current_line[0];
                    while (line.size() < maxWidth) {
                        line += " ";
                    }
                } 
                else {
                    int total_spaces = maxWidth - current_len;
                    int gaps = num_words - 1;
                    
                    int base_spaces = total_spaces / gaps;
                    int extra_spaces = total_spaces % gaps; 
                    
                    for (int j = 0; j < num_words; j++) {
                        line += current_line[j];
                        if (j < gaps) {
                            for (int s = 0; s < base_spaces; s++) line += " ";
                            if (j < extra_spaces) line += " ";
                        }
                    }
                }
                
                ans.push_back(line); 
                
                current_line.clear();
                current_len = 0;
                cnt = 0;
                i--; 
            }
        }
        
        if (!current_line.empty()) {
            string line = "";
            for (int j = 0; j < current_line.size(); j++) {
                line += current_line[j];
                if (j < current_line.size() - 1) line += " "; 
            }
            while (line.size() < maxWidth) {
                line += " ";
            }
            ans.push_back(line);
        }
        
        return ans;
    }
};
