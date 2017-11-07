class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> vans = {0};
        unordered_set<int> st = {0};
        while (true) {         
            bool changed = false;
            for (int i = 0; i < n; i++) {
                // toggle a bit at position i
                int next = vans[vans.size() - 1] ^ (1 << i);
                if (st.find(next) == st.end()) {
                    vans.push_back(next);
                    st.insert(next);
                    changed = true;
                    break;
                }
            }
            
            if (!changed ) {
                break;
            }
        }
        
        return vans;
    }
};
