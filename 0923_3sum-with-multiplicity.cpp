class Solution {
private:
    int MOD = 1e9 + 7;
    vector<pair<int, int>> vb;
    int comb(long n, long r) {
        if (r == 0) return 1;
        if (n < r) return 0;
        
        if (r > n / 2)
            return comb(n, n - r); 
        long res = 1; 
        for (long k = 1; k <= r; k++) {
            res *= n - k + 1;
            res /= k;
        }
        return res % MOD;
    }
    int binSearch(int lo, int hi, int trg) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (vb[mid].first == trg) {
                return vb[mid].second;
            } else if (vb[mid].first > trg) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return 0;
    }
public:
    int threeSumMulti(vector<int>& A, int target) {
        map<int, int> mp;
        for (int a : A) {
            if (mp.count(a) == 0) mp[a] = 0;
            mp[a]++;
        }
        
        for (auto kv : mp) {
            vb.push_back({kv.first, kv.second});
        }
        
        int ans = 0;
        for (int i = 0; i < vb.size(); i++) {
            int j = i + 1, k = vb.size() - 1;
            while (j < k) {
                int sum = vb[i].first + vb[j].first + vb[k].first;
                if (sum == target) {
                    int cnt = vb[i].second * vb[j].second * vb[k].second % MOD;
                    ans = (ans + cnt) % MOD;
                    j++;
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
            
            int trg = target - vb[i].first * 2;
            if (trg == vb[i].first) {
                ans += comb(vb[i].second, 3) % MOD;
            } else if (trg > vb[i].first) {
                ans += comb(vb[i].second, 2) * binSearch(i + 1, vb.size() - 1, trg) % MOD;
            } else {
                ans += comb(vb[i].second, 2) * binSearch(0, i - 1, trg) % MOD;
            }
            ans %= MOD;
        }
        
        return ans;
    }
};
