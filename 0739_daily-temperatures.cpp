// slow, but elegant
// inspired by "Explore Stack & Queue" tutorial.
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> vi(T.size(), 0);
        stack<pair<int, int>> st;
        for (int i = 0; i < T.size(); i++) {
            while (!st.empty() && st.top().first < T[i]) {
                vi[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({T[i], i});
        }
        return vi;
    }
};

// fast
class Solution {
public:
    static const int MAX_TEMP = 100;
    static const int MIN_TEMP = 30;
    vector<int> dailyTemperatures(vector<int>& vt) {
        int n = vt.size();
        vector<int> vi(n, 0);
        if (n <= 1) return vi;
        
        vector<stack<int>> vsi(MAX_TEMP - MIN_TEMP + 1, stack<int>());
        for (int i = n - 1; i >= 0; i--) {
            vsi[vt[i] - MIN_TEMP].push(i);
        }
        
        // for (int i = 0; i < vsi.size(); i++) {
        //     if (!vsi[i].empty()) {
        //         printf("T=%d POS=%d\n", i + MIN_TEMP, vsi[i].top());
        //     }
        // }
        // printf("\n");
        
        for (int i = 0; i + 1 < n; i++) {
            int t = vt[i] - MIN_TEMP;
            vsi[t].pop();
            
            int minj = -1;
            for (int j = t + 1; j < vsi.size(); j++) {
                if (vsi[j].empty()) continue;
                
                if (minj < 0) {
                    minj = j;
                } else if (vsi[j].top() < vsi[minj].top()) {
                    // printf("POS=%d potential NEXT_TEMP=%d at POS=%d\n", i, j + MIN_TEMP, vsi[j].top());
                    minj = j;
                }
            }
            
            if (minj > 0) {
                vi[i] = vsi[minj].top() - i;
            }
        }
        return vi;
    }
};
