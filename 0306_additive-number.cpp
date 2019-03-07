class Solution {
private:
    vector<int> add(vector<int>& a, vector<int>& b) {
        vector<int> c;
        int n = a.size(), m = b.size();
        int q = 0;
        int i;
        for (i = 0; i < min(n, m); i++) {
            int d = a[i] + b[i] + q;
            c.push_back(d % 10);
            q = d / 10;
        }
        
        auto e = (n > m) ? a : b;
        for (; i < e.size(); i++) {
            int d = e[i] + q;
            c.push_back(d % 10);
            q = d / 10;
        }
    
        if (q > 0) {
            c.push_back(q);
        }
        while (c.size() > 1 && c[c.size() - 1] == 0) {
            c.pop_back();
        }
        return c;
    }
    
    vector<int> toVector(string s) {
        vector<int> v(s.size());
        for (int i = 0; i < s.size(); i++) {
            v[i] = (int) (s[i] - '0');
        }
        reverse(v.begin(), v.end());
        return v;
    }
    
    string toString(vector<int> v) {
        string s = "";
        for (int i : v) {
            s += to_string(i);
        }
        return s;
    }
    
    bool check(string num, int aBegin, int aLen, int bBegin, int bLen) {
        string sf = num.substr(aBegin, aLen);
        string ss = num.substr(bBegin, bLen);
        
        if ((sf.size() > 1 && sf[0] == '0') || ss.size() > 1 && ss[0] == '0'){
            return false;
        }
        
        auto a = toVector(sf);
        auto b = toVector(ss);
        vector<int> sum = add(a, b);
        reverse(sum.begin(), sum.end());
        string nxt = toString(sum);
        
        // printf("%s + %s = %s\n", sf.c_str(), ss.c_str(), nxt.c_str());
        
        int idx = bBegin + bLen;
        if (num.find(nxt, idx) == idx) {
            return (num.size() == idx + nxt.size()) ? true :
                check(num, bBegin, bLen, idx, nxt.size());
        }
        
        return false;
    }
    
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.size(); i++) {            
            for (int j = 1; j < num.size() - i; j++) {
                if (check(num, 0, i, i, j)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
