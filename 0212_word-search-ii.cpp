class Solution {
private:
    struct TrieNode {
        bool isTerminal = false;
        unordered_map<char, TrieNode*> children;
    };
    
    bool is(int r, int c, int rows, int cols) {
        return 0 <= r && r < rows && 0 <= c && c < cols;
    }
    
    struct State {
        TrieNode* node;
        string word;
        int row;
        int col;
        vector<vector<bool>> used;
        State(TrieNode* n, string w, int r, int c, vector<vector<bool>> u):
            node(n), word(w), row(r), col(c), used(u) {};
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size();
        int cols = rows > 0 ? board[0].size() : 0;
        
        auto root = new TrieNode();
        for (auto word : words) {
            auto node = root;
            for (char ch : word) {
                if (!node->children.count(ch)) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }
            node->isTerminal = true;
        }
        
        // queue<pair<TrieNode*, string>> q;
        // q.push({root, ""});
        // while (!q.empty()) {
        //     auto front = q.front();
        //     q.pop();
        //     if (front.first->isTerminal) {
        //         cout << front.second << endl;
        //     }
        //     for (auto kv : front.first->children) {
        //         q.push({kv.second, front.second + kv.first});
        //     }
        // }
        
        unordered_set<string> st;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (!root->children.count(board[r][c])) {
                    continue;
                }
                
                queue<State*> q;
                vector<vector<bool>> used(rows, vector<bool>(cols, false));
                used[r][c] = true;
                q.push(new State(root, "", r, c, used));
                while (!q.empty()) {
                    auto state = q.front();
                    q.pop();
                    
                    int row = state->row, col = state->col;
                    auto w = state->word + board[row][col];
                    auto u = state->used;
                    auto n = state->node->children[board[row][col]];
                    // printf("State w=%s [%d %d]\n", w.c_str(), row, col);
                    if (n->isTerminal) {
                        st.insert(w);
                    }
                    if (is(row, col+1, rows, cols) && !u[row][col+1] && n->children.count(board[row][col+1])) {
                        // puts("EAST");
                        auto unext(u);
                        unext[row][col+1] = true;
                        q.push(new State(n, w, row, col+1, unext));
                    }
                    if (is(row+1, col, rows, cols) && !u[row+1][col] && n->children.count(board[row+1][col])) {
                        // puts("SOUTH");
                        auto unext(u);
                        unext[row+1][col] = true;
                        q.push(new State(n, w, row+1, col, unext));
                    }
                    if (is(row, col-1, rows, cols) && !u[row][col-1] && n->children.count(board[row][col-1])) {
                        // puts("WEST");
                        auto unext(u);
                        unext[row][col-1] = true;
                        q.push(new State(n, w, row, col-1, unext));
                    }
                    if (is(row-1, col, rows, cols) && !u[row-1][col] && n->children.count(board[row-1][col])) {
                        // puts("NORTH");
                        auto unext(u);
                        unext[row-1][col] = true;
                        q.push(new State(n, w, row-1, col, unext));
                    }
                }
            }
        }
        vector<string> ans;
        ans.insert(ans.end(), st.begin(), st.end());
        return ans;
    }
};
