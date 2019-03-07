class Solution {
public:
    double area(double a, double b, double c) {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double side(int x1, int y1, int x2, int y2) {
        double a = abs(x2 - x1);
        double b = abs(y2 - y1);
        return sqrt(a * a + b * b);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double mx = 0.0;
        int sz = points.size();
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                for (int k = 0; k < sz; k++) {
                    auto pi = points[i];
                    auto pj = points[j];
                    auto pk = points[k];
                    double a = side(pi[0], pi[1], pj[0], pj[1]);
                    double b = side(pj[0], pj[1], pk[0], pk[1]);
                    double c = side(pi[0], pi[1], pk[0], pk[1]);
                    mx = max(mx, area(a, b, c));
                }
            }
        }
        return mx;
    }
};