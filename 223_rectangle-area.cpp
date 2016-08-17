class Solution {
private:
    bool isBetween(int i, int j, int k) {
        return min(i, j) <= k && k <= max(i, j);
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        vector<int> x = {A, C, E, G};
        vector<int> y = {B, D, F, H};
        int area = (abs(x[0]-x[1]) * abs(y[0]-y[1])) + (abs(x[2]-x[3]) * abs(y[2]-y[3]));
        int intrsct = 0;
        if ((isBetween(x[0], x[1], x[2]) || isBetween(x[0], x[1], x[3]) || isBetween(x[2], x[3], x[0]) || isBetween(x[2], x[3], x[1])) &&
            (isBetween(y[0], y[1], y[2]) || isBetween(y[0], y[1], y[3]) || isBetween(y[2], y[3], y[0]) || isBetween(y[2], y[3], y[1]))) 
        {
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
            intrsct = (abs(x[1] - x[2]) * abs(y[1] - y[2]));
        }
        return area - intrsct;
    }
};
