class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<int> visited;
        for (string s : deadends) {
            visited.insert(stoi(s));
        }
        
        int ans = INT_MAX;
        vector<int> vi(4, 0);
        int t = stoi(target);
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            // printf("%04d steps=%d\n", p.first, p.second);
            if (p.first == t) {
                ans = min(ans, p.second);
                continue;
            }
            if (visited.count(p.first)) continue;
            visited.insert(p.first);
            
            vi[0] = p.first / 1000;
            vi[1] = p.first / 100 % 10;
            vi[2] = p.first / 10 % 10;
            vi[3] = p.first % 10;
            for (int i = 0; i < 4; i++) {
                int tmp = vi[i];
                vi[i] = (vi[i] + 1 + 10) % 10;
                int k = vi[0] * 1000 + vi[1] * 100 + vi[2] * 10 + vi[3];
                if (!visited.count(k)) {
                    q.push({k, p.second + 1});
                }
                vi[i] = tmp;
                vi[i] = (vi[i] - 1 + 10) % 10;
                k = vi[0] * 1000 + vi[1] * 100 + vi[2] * 10 + vi[3];
                if (!visited.count(k)) {
                    q.push({k, p.second + 1});
                }
                
                vi[i] = tmp;
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
