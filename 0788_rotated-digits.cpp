class Solution {
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        int X = -1e6;
        vector<int> vi = {0, 1, 5, X, X, 2, 9, X, 8, 6};
        for (int i = 1; i <= N; i++) {
            string s = to_string(i);
            int r = 0;
            bool valid = true;
            for (int j = 0; j < s.size(); j++) {
                int n = (int) (s[j] - '0');
                int k = vi[n];
                if (k == X) {
                    valid = false;
                }
                r = r * 10 + k;
            }
            cnt += valid && (r != i);
        }
        return cnt;
    }
};
