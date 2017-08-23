class Solution {
public:
    int romanToInt(string s) {
        vector<int> v;
        int val;
        for (char ch : s) {
            val = 0;
            switch (ch) {
                case 'I':
                    val = 1;
                    break;
                case 'V':
                    val = 5;
                    break;
                case 'X':
                    val = 10;
                    break;
                case 'L':
                    val = 50;
                    break;
                case 'C':
                    val = 100;
                    break;
                case 'D':
                    val = 500;
                    break;
                case 'M':
                    val = 1000;
                    break;
            }
            v.push_back(val);
        }
        
        int ans = 0;
        int mx = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            ans += (v[i] < mx ? -1 * v[i] : v[i]);
            mx = max(mx, v[i]);
        }
        
        return ans;
    }
};
