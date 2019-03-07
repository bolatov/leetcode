class Solution {
private:
    // vector of ints to string for debugging purposes
    string to_vstr(vector<int> v) {
        string s = "";
        for (int i = 0; i < v.size(); i++) {
            s += to_string(v[i]);
            if (i != v.size() - 1) s += ".";
        }
        return s;
    }
    void f(vector<vector<int>>& vr, vector<int>& vc, vector<int>& vi, int pos, int dots, int offset) {
        for (int i = 0; i < offset; i++) printf("\t");
        printf("f(): pos=%d, vc=%s, dots=%d\n", pos, to_vstr(vc).c_str(), dots);
        
        // if no dots are left, then gather the rest of the digits
        // into IP-address element
        if (dots == 0) {
            int n = 0;
            bool ok = 0; // whether anything happened
            for (; pos < vi.size(); pos++) {
                ok = 1;
                n *= 10;
                n += vi[pos];
            }
            if (ok) {
                vc.push_back(n);
                vr.push_back(vc);
            }
            return;
        }
        
        // IP-address element can contain at most 3 digits
        for (int i = 1; i <= 3; i++) {
            int n = 0;
            bool ok = 0; // whether anything happened
            for (int j = pos; j < pos + i && j < vi.size(); j++) {
                ok = 1;
                n *= 10;
                n += vi[j];
            }
            if (ok) {
                vector<int> vci(vc);
                vci.push_back(n);
                f(vr, vci, vi, pos+i, dots-1, offset+1);
            }
        }
    }
    
    // checks whether IP-address element is in valid range
    bool is(int i) {
        return 0 <= i && i <= 255;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        // prepare a vector for final results
        vector<vector<int>> vr;
        
        // vector vi for storing each digit
        // vector vc to store current (temporary) IP-address
        vector<int> vi, vc;
        for (char ch : s) {
            vi.push_back(ch - '0');
        }
        f(vr, vc, vi, 0, 3, 0);
        vector<string> vs;
        for (auto v : vr) {
            string t = "";
            if (is(v[0]) && is(v[1]) && is(v[2]) && is(v[3])) {
                for (int i = 0; i < v.size(); i++) {
                    t += to_string(v[i]);
                    if (i != v.size() - 1) t += ".";
                }
                
                // assert parsed IP length (without dots) is equal to IP-address s
                if (s.size() == t.size()-3) vs.push_back(t);
            }
        }
        return vs;
    }
};
