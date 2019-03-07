class Solution {
  private:
    bool between(int i, int mn, int mx) { return mn <= i && i <= mx; }

  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n, 0));
        if (n == 0)
            return m;

        int val = 1, nn = n * n;
        int i = 0, j = 0, k = 0;

        // Offsets to specify direction in which to iterate
        // 0=EAST, 1=SOUTH, 2=WEST, 3=NORTH
        int idir = 0, jdir = 1;
        while (val <= nn) {
            for (; between(i, 0, n - 1) && between(j, 0, n - 1) && m[i][j] == 0;
                 i += idir, j += jdir) {
                m[i][j] = val++;
            }
            i -= idir;
            j -= jdir;

            // Choose next direction
            k = (k + 1) % 4;
            switch (k) {
            case 0:
                idir = 0, jdir = 1;
                break;
            case 1:
                idir = 1, jdir = 0;
                break;
            case 2:
                idir = 0, jdir = -1;
                break;
            case 3:
                idir = -1, jdir = 0;
                break;
            default:
                break;
            }
            i += idir;
            j += jdir;
        }
        return m;
    }
};