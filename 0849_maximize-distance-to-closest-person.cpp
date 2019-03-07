class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        size_t dist = 1;
        size_t pos = 0;
        for (size_t i = 1; i <= seats.size(); i++) {
            if (seats[i - 1]) {
                size_t d = (pos == 0) ? i - 1 : (i - pos) / 2;
                dist = max(d, dist);
                pos = i;
            }
        }
        dist = max(dist, seats.size() - 1 - (pos - 1));
        return dist;
    }
};
