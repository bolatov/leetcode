class WordDictionary {
private:
    struct TrieNode {
        bool isWord = false;
        unordered_map<char, TrieNode*> children;
    };
    TrieNode* root;
    
    bool dfsSearch(TrieNode* node, string& s, int i) {
        if (i >= s.size()) return node->isWord;
        for (; i < s.size(); i++) {
            if (s[i] != '.') {
                if (node->children.count(s[i]) <= 0) return false;
                node = node->children[s[i]];
            } else {
                bool ans = false;
                for (auto kv : node->children) {
                    if (dfsSearch(kv.second, s, i + 1)) {
                        return true;
                    }
                }
                return false;
            }
        }
        return node->isWord;
    }
    
    bool bfsSearch(string word) {
        queue<pair<TrieNode*, string>> q;
        q.push({root, word});
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            
            auto cur = f.first;
            auto s = f.second;
            if (s.empty()) {
                if (cur->isWord) {
                    return true;
                }
                continue;
            }
            
            if (s[0] == '.') {
                for (auto kv : cur->children) {
                    q.push({kv.second, s.substr(1)});
                }
            } else if (cur->children.count(s[0])) {
                q.push({cur->children[s[0]], s.substr(1)});
            }
        }
        return false;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        this->root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto cur = root;
        for (char ch : word) {
            if (!cur->children.count(ch)) {
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfsSearch(root, word, 0);
        // return bfsSearch(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
