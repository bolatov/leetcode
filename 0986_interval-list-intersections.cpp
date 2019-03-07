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
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> vi;
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            auto a = A[i];
            auto b = B[j];
            int be = max(a.start, b.start);
            int en = min(a.end, b.end);
            if (be <= en) {
                vi.push_back(Interval(be, en));
            }
            if (en == a.end) {
                i++;
            } 
            if (en == b.end ){
                j++;
            }
        }
        return vi;
    }
};
