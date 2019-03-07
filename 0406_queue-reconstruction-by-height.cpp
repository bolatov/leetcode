struct ppii {
    pair<int, int> p;
    pair<int, int> q;
    ppii(int i, int j): p(i, j), q(i, j){}
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& p) {
        int n = p.size();
        vector<pair<int, int>> q;
        
        vector<ppii> vppii;
        for (auto pi : p) {
            vppii.push_back(ppii(pi.first, pi.second));
        }
        
        for (int i = 0; i < n; i++) {
            sort(vppii.begin() + i, vppii.end(), [](const ppii i, const ppii j) {
                return i.q.second == j.q.second ? (i.q.first < j.q.first) : (i.q.second < j.q.second);
            });
            auto item = vppii[i];
            int ho = item.p.first;
            int ko = item.p.second;
            q.push_back({ho, ko});
            
            int h = item.q.first;
            for (int j = i + 1; j < n; j++) {
                if (vppii[j].q.first <= h) {
                    vppii[j].q.second--;
                }
            }
        }
        
        return q;
    }
};
