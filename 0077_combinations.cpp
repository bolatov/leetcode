class Solution {
  private:
    vector<int> cp(vector<int> s) {
        vector<int> v;
        for (auto i : s)
            v.push_back(i);
        return v;
    }

  public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> vi;
        if (n < k)
            return vi;

        queue<vector<int>> q;
        for (int i = 1; i <= n - k + 1; i++) {
            vector<int> v = {i};
            q.push(v);
        }
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            if (v.size() == k) {
                vi.push_back(v);
            }

            for (int i = v[v.size() - 1] + 1; i <= n; i++) {
                auto vc = cp(v);
                vc.push_back(i);
                q.push(vc);
            }
        }
        return vi;
    }
};