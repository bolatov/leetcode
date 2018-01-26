struct TrieNode {
    bool isTerminal;
    unordered_map<char, TrieNode*> children;
    TrieNode(): isTerminal(false) {}
};

struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() < second.size();
    }
};

class Solution {
private:
    TrieNode* buildTrie(vector<string>& dict) {
        TrieNode* trie = new TrieNode();
        for (string w : dict) {
            TrieNode* node = trie;
            bool shorterExists = false;
            for (int i = 0; i < w.size() && !shorterExists; i++) {
                if (node->children.find(w[i]) == node->children.end()) {
                    node->children[w[i]] = new TrieNode();
                } else if (node->children[w[i]]->isTerminal) {
                    shorterExists = true;
                }
                node = node->children[w[i]];
            }
            node->isTerminal = true;
        }
        return trie;
    }
    
    string findRoot(TrieNode* trie, string word) {
        for (int i = 0; i < word.size(); i++) {
            if (trie->children.find(word[i]) == trie->children.end()) {
                break;
            }
            
            trie = trie->children[word[i]];
            if (trie->isTerminal) {
                return word.substr(0, i + 1);
            }
        }
        return word;
    }
    
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
public:
    string replaceWords(vector<string>& dict, string sentence) {
        vector<string> words = split(sentence);
        compare c;
        sort(dict.begin(), dict.end(), c);
        TrieNode* trieNode = buildTrie(dict);
        string ans = "";
        for (string word : words) {
            string root = findRoot(trieNode, word);
            if (!ans.empty()) {
                ans += " ";
            }
            ans += root;
        }
        return ans;
    }
};
