class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int l = 1;
        int r = 0;
        for (char ch : S) {
            int w = widths[(int) (ch - 'a')];
            if (r + w > 100) {
                l++;
                r = 0;
            } 
            r += w;
        }
        return {l, r};
    }
};