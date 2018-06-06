class Solution {
public:
    void dfs(vector<vector<int>>& g, vector<vector<int>>& vvi, vector<int>& vi, int i) {
        vi.push_back(i);
        if (i == g.size() - 1) vvi.push_back(vi);
        for (int j : g[i]) {
            vector<int> vj(vi);
            dfs(g, vvi, vj, j);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> vvi;
        vector<int> vi;
        dfs(graph, vvi, vi, 0);
        return vvi;
    }
};
