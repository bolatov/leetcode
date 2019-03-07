class Solution {
private:
    int dist(string s, string t) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) cnt += (int) (s[i] != t[i]);
        return cnt;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<int>> g(wordList.size(), vector<int>());
        for (int i = 0; i < g.size(); i++) {
            for (int j = i + 1; j < g.size(); j++) {
                if (dist(wordList[i], wordList[j]) == 1) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        int ans = INT_MAX;
        vector<bool> u(g.size(), false);
        queue<pair<int, int>> q;
        for (int i = 0; i < g.size(); i++) {
            if (dist(beginWord, wordList[i]) == 1) {
                q.push({i, 2});
            }
        }
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            if (u[f.first]) continue;
            u[f.first] = true;
            if (wordList[f.first] == endWord) {
                ans = min(ans, f.second);
                continue;
            }
            for (int nxt : g[f.first]) {
                if (!u[nxt]) {
                    q.push({nxt, f.second + 1});
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
