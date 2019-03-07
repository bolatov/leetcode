class Solution {
public:
    /**
     * O(nlogn) solution
     */
    vector<int> twoSum(vector<int>& v, int t) {
        // work with the sorted copy of original vector
        vector<int> u(v);
        sort(u.begin(), u.end());   // O(nlogn)
        
        
        for (int i = 0; i < u.size(); i++) {    // O(n)
            int ti = t - u[i];
            
            // do binary search on the elements to
            // the right of the current one (v[i])
            int lo = i + 1, hi = u.size() - 1;
            while (lo <= hi) {  // O(logn)
                int m = lo + (hi - lo) / 2;
                if (u[m] == ti) {
                    
                    // numbers are found
                    // retrieve original indices from vector v
                    vector<int> vi(2);
                    bool notFound1 = 1, notFound2 = 1;
                    for (int k = 0; k < v.size(); k++) {
                        if (v[k] == u[i] && notFound1) {
                            vi[0] = k;
                            notFound1 = 0;
                        } else if (v[k] == u[m] && notFound2) {
                            vi[1] = k;
                            notFound2 = 0;
                        }
                    }
                    return vi;
                } else if (u[m] < ti) {
                    lo = m + 1;
                } else {
                    hi = m - 1;
                }
            }
        }
        return {};
    }
};
