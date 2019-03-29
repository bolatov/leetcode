double dist(int i, int j) {
    return sqrt((double)(i*i + j*j));
}
class Solution {   
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto comp = [](const vector<int>& p1, const vector<int>& p2) {
            double d1 = dist(p1[0], p1[1]);
            double d2 = dist(p2[0], p2[1]);
            return d1 < d2;
        };
        sort(points.begin(), points.end(), comp);
        vector<vector<int>> vvi(points.begin(), points.begin() + K);
        return vvi;
    }
};
