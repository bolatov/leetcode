class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        if (n <= 0) {
            return v;
        }
        
        // string -> {numberOfOpenBraces, numberOfCloseBraces}
        queue<pair<string, pair<int, int>>> q;
        q.push({"(", {1, 0}});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p.first.size() == 2 * n) {
                v.push_back(p.first);
                continue;
            }
            
            int open = p.second.first;
            int close = p.second.second;
            if (open + 1 <= n) {
                q.push({p.first + "(", {open + 1, close}});
            }
            
            if (close + 1 <= open) {
                q.push({p.first + ")", {open, close + 1}});
            }
        }
        
        return v;
    }
};
