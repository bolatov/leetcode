class Solution {
public:
    string originalDigits(string s) {
        vector<pair<string, char>> vp = {
            {"eight", '8'},
            {"zero",  '0'},
            {"six",   '6'},
            {"two",   '2'},
            {"three", '3'},
            {"four",  '4'},
            {"five",  '5'},
            {"seven", '7'},
            {"nine",  '9'},
            {"one",   '1'},
        };
        vector<int> vi(26, 0);
        for (char ch : s) {
            vi[ch-'a']++;
        }
        
        string ans = "";
        for (auto p : vp) {
            string k = p.first;
            char v = p.second;
            int minCount = INT_MAX;
            for (char ch : k) {
                minCount = min(minCount, vi[ch-'a']);
            }
            if (minCount == 0) continue;
            ans += string(minCount, v);
            for (char ch : k) {
                vi[ch-'a'] -= minCount;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
