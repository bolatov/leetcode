class Solution {
public:
    vector<string> split(string sentence) {
        vector<string> vs;
        string buffer = "";
        for (char ch : sentence) {
            if (ch == ' ') {
                if (!buffer.empty()) {
                    vs.push_back(buffer);
                    buffer = "";
                }
            } else {
                buffer += ch;
            }
        }
        if (!buffer.empty()) {
            vs.push_back(buffer);
        }
        return vs;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> st(dict.begin(), dict.end());
        vector<string> words = split(sentence);
        string ans = "";
        for (string word : words) {
            for (int i = 1; i <= word.size(); i++) {
                if (st.find(word.substr(0, i)) != st.end()) {
                    word = word.substr(0, i);
                    break;
                }
            }
            if (!ans.empty()) {
                ans += " ";
            }
            ans += word;
        }
        return ans;
    }
};
