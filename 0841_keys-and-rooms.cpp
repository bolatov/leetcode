class Solution {
public:
    void dfs(vector<vector<int>>& g, vector<bool>& u, int i) {
        u[i] = true;
        for (int j : g[i]) if (!u[j]) dfs(g, u, j);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> u(rooms.size(), false);
        dfs(rooms, u, 0);
        int cnt = 0;
        for (bool i : u) cnt += (int) i;
        return rooms.size() == cnt;
    }
};
