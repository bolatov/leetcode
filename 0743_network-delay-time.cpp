class Solution {
private:
    void dfs(vector<vector<pair<int, int>>>& g, vector<vector<int>>& times, int k, vector<int>& vd) {
        for (auto p : g[k]) {
            // Check if the node is not visited, or there is an
            // alternative faster path to the node.
            if (vd[p.first] < 0 || (vd[k] + p.second < vd[p.first])) {
                vd[p.first] = vd[k] + p.second;
                dfs(g, times, p.first, vd);
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Create a directed graph, storing the corresponding time `w` between
        // nodes `u` and `v`
        vector<vector<pair<int, int>>> g(N + 1, vector<pair<int, int>>());
        for (auto uvw : times) {
            int u = uvw[0], v = uvw[1], w = uvw[2];
            g[u].push_back({v, w});
        }
        
        // Init a vector with a final time node receiving the signal.
        vector<int> vd(N + 1, -1);
        vd[K] = 0;
        
        // Do a DFS traversal sending the signal from node `K`
        // to all other nodes.
        dfs(g, times, K, vd);
        
        // Gather the result. If the signal did not reach the node,
        // then it holds value `-1` in vector `vd`.
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (vd[i] < 0) return -1;
            // printf("vd[%d] = %d\n", i, vd[i]);
            ans = max(ans, vd[i]);
        }
        return ans;
    }
};
