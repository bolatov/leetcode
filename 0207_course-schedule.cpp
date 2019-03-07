class Solution {
  private:
    bool dfs(vector<set<int>> &g, vector<int> &c, int s) {
        // set color to gray
        c[s] = 1;
        for (int t : g[s]) {
            if (c[t] == 1 || dfs(g, c, t)) {
                return 1;
            }
        }

        // set color to black
        c[s] = 2;
        return 0;
    }

  public:
    bool canFinish(int n, vector<pair<int, int>> &pr) {
        vector<set<int>> g(n, set<int>());
        for (auto p : pr) {
            g[p.second].insert(p.first);
        }

        // colors: 0-white, 1-gray, 2-black
        vector<int> c(n, 0);

        // start a DFS on each vertex
        for (int i = 0; i < n; i++) {
            if (c[i] == 0 && dfs(g, c, i))
                return 0;
        }

        return 1;
    }
};