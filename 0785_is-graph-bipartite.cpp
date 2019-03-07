class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vc(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (vc[i] != -1) continue;
            queue<int> q;
            q.push(i);
            vc[i]++;
            while (!q.empty()) {
                int k = q.front();
                q.pop();
                for (int ch : graph[k]) {
                    if (vc[ch] == -1) {
                        vc[ch] = vc[k] + 1;
                        q.push(ch);
                    } else if (vc[ch] == vc[k]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
