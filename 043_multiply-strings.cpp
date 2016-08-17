#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    vector<int> convert(string s) {
        reverse(s.begin(), s.end());
        vector<int> w;
        for (char ch : s) {
            w.push_back(ch - '0');
        }
        return w;
    }
    vector<int> mul(vector<int> &v, int k) {
        vector<int> w;
        int m = 0, q = 0;
        for (int i = 0; i < (int)v.size(); ++i) {
            m = v[i] * k + q;
            w.push_back(m % 10);
            q = m / 10;
        }
        if (q) {
            w.push_back(q);
        }
        return w;
    }
    vector<int> add(vector<int> &v, vector<int> &u) {
        vector<int> w;
        int q = 0, sum = 0;
        int n = (int)v.size(), m = (int)u.size();
        for (int i = 0; i < max(n, m); i++) {
            sum = (i < n ? v[i] : 0) + (i < m ? u[i] : 0) + q;
            q = sum / 10;
            w.push_back(sum % 10);
        }
        if (q) {
            w.push_back(q);
        }

        return w;
    }

  public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        auto v = convert(num1);
        auto u = convert(num2);
        vector<int> ans;
        for (int i = 0; i < (int)v.size(); i++) {
            vector<int> t = mul(u, v[i]);
            vector<int> mu(i, 0);
            for (int j : t) {
                mu.push_back(j);
            }
            if (ans.empty()) {
                ans = t;
            } else {
                ans = add(ans, mu);
            }
        }
        string s = "";
        for (int i = 0; i < (int)ans.size(); ++i) {
            s += to_string(ans[i]);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution s;
    int i = 2159, j = 101;
    cout << s.multiply(to_string(i), to_string(j)) << " = " << (i * j) << endl;
    return 0;
}