class Solution {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int idx = -1;
    };
    
    bool isPalindrome(string& w, int be, int en) {
        while (be < en) {
            if (w[be] != w[en]) {
                return false;
            }
            be++;
            en--;
        }
        return true;
    }
    TrieNode* buildTrie(vector<string>& words) {
        auto root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            auto node = root;
            for (char ch : words[i]) {
                if (!node->children.count(ch)) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }
            node->idx = i;
        }
        return root;
    }
    void bfs(TrieNode* node) {
        queue<TrieNode*> q;
        q.push(node);
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            cout << "Node " << f << " has keys:" << endl;
            for (auto kv : f->children) {
                cout << "  " << kv.first << " -> " << kv.second << endl;
                q.push(kv.second);
            }
            cout << endl;
        }
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        auto root = buildTrie(words);
        // bfs(root);
        // puts("----------------------------");
        vector<vector<int>> vvi;
        for (int iWord = 0; iWord < words.size(); iWord++) {
            auto curNode = root;
            string w = words[iWord];
            // cout << w << endl;
            list<pair<int, int>> li; // for prefixes
            int j;
            for (j = w.size() - 1; j >= 0; j--) {
                char ch = w[j];
                if (curNode->idx >= 0 && curNode->idx != iWord) {
                    li.push_back({j, curNode->idx});
                }
                if (!curNode->children.count(ch)) {
                    // printf("  j=%d break\n", j);
                    break;
                }
                curNode = curNode->children[ch];
            }
            
            // check prefixes
            for (auto p : li) {
                if (isPalindrome(w, 0, p.first)) {
                    vvi.push_back({p.second, iWord});
                }
            }
            
            // check leaves
            if (j < 0 && curNode) {
                // printf("  w=%s\n", w.c_str());
                queue<TrieNode*> q;
                q.push(curNode);
                while (!q.empty()) {
                    auto f = q.front();
                    q.pop();
                    if (f->idx >= 0 && f->idx != iWord && isPalindrome(words[f->idx], w.size(), words[f->idx].size() - 1)) {
                        vvi.push_back({f->idx, iWord});
                    }
                    for (auto kv : f->children) {
                        // printf("    key=%c\n", kv.first);
                        q.push(kv.second);
                    }
                }
            }
        }
        return vvi;
    }
};
