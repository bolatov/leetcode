class Solution {
private:
    unordered_map<int, unordered_set<int>> visited;
    unordered_map<int, list<int>> rows, cols;
    bool isVisited(int row, int col) {
        return visited.count(row) > 0 && visited[row].count(col) > 0;
    }
    void setVisited(int row, int col) {
        if (!visited.count(row)) {
            visited[row] = unordered_set<int>();
        }
        visited[row].insert(col);
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();        
        for (auto vi : stones) {
            int row = vi[0], col = vi[1];
            if (!rows.count(row)) {
                rows[row] = list<int>();
            }
            if (!cols.count(col)) {
                cols[col] = list<int>();
            }
            rows[row].push_back(col);
            cols[col].push_back(row);
        }
        int ans = 0;
        for (auto vi : stones) {
            int row = vi[0], col = vi[1];
            if (!isVisited(row, col)) {
                stack<pair<int, int>> st;
                st.push({row, col});
                setVisited(row, col);
                while (!st.empty()) {
                    auto top = st.top();
                    st.pop();
                    int i = top.first, j = top.second;
                    for (int c : rows[i]) {
                        if (!isVisited(i, c)) {
                            st.push({i, c});
                            setVisited(i, c);
                            // printf("visit %d %d\n", i, c);
                            ans++;
                        }
                    }
                    for (int r : cols[j]) {
                        if (!isVisited(r, j)) {
                            st.push({r, j});
                            setVisited(r, j);
                            // printf("visit %d %d\n", row, j);
                            ans++;
                        }
                    }
                }
            }
        } 
        return ans;
    }
};
