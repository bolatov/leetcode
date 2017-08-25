class Solution {
private:
    double dist(pair<int, int>& p, pair<int, int>& q) {
        double a = (double) abs(p.first - q.first);
        double b = (double) abs(p.second - q.second);
        return sqrt(a * a + b * b);
    }

public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int sum = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> mp;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) {
                    continue;
                }
                double d = dist(points[i], points[j]);
                if (mp.find(d) == mp.end()) {
                    mp[d] = 0;
                }
                mp[d]++;
            }
            
            for (auto p : mp) {
                if (p.second <= 1) {
                    continue;
                }
                sum += p.second * (p.second - 1);
            }
        }
        return sum;
    }
};
