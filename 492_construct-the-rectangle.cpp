class Solution {
public:
    vector<int> constructRectangle(int area) {
        int len = area, wid = 1;
        int bestDiff = len - wid;
        for (int i = 2; i * 2 <= area; i++) {
            int j = area / i;
            if (i * j == area && abs(i - j) < bestDiff) {
                bestDiff = abs(i - j);
                len = max(i, j);
                wid = min(i, j);
            }
        }
        return {len, wid};
    }
};
