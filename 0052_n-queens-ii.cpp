class Solution {
private:
    int count(vector<bool>& c, vector<bool>& d1, vector<bool>& d2, int y) {
        int n = c.size();
        if (y == n) {
            return 1;
        }
        
        int cnt = 0;
        for (int x = 0; x < c.size(); x++) {
            if (c[x] || d1[x + y] || d2[x - y + n - 1]) {
                continue;
            }
            c[x] = d1[x + y] = d2[x - y + n - 1] = 1;
            cnt += count(c, d1, d2, y + 1);
            c[x] = d1[x + y] = d2[x - y + n - 1] = 0;
        }
        return cnt;
    }
public:
    int totalNQueens(int n) {
        vector<bool> c(n, 0), d1(n, 0), d2(n, 0);
        return count(c, d1, d2, 0);
    }
};
