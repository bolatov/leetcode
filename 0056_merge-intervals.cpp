/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    struct less_than_key {
        inline bool operator() (const Interval& i1, const Interval& i2) {
            return (i1.start < i2.start);
        }
    };
public:
    vector<Interval> merge(vector<Interval>& vs) {
        vector<Interval> v;
        sort(vs.begin(), vs.end(), less_than_key());
        for (int i = 1; i < vs.size(); i++) {
            if (vs[i - 1].end < vs[i].start) {
                v.push_back(vs[i - 1]);
            } else {
                vs[i].start = min(vs[i - 1].start, vs[i].start);
                vs[i].end = max(vs[i - 1].end, vs[i].end);
            }
        }
        if (!vs.empty()) {
            v.push_back(vs[vs.size() - 1]);
        }
        return v;
    }
};
