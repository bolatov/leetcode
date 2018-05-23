class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for (string s : ops) {
            if (s == "C") {
                v.pop_back();
            } else if (s == "D") {
                int d = v[v.size() - 1] * 2;
                v.push_back(d);
            } else if (s == "+") {
                int lst = v.size();
                v.push_back(v[lst - 1] + v[lst - 2]);
            } else {
                int d = stoi(s);
                v.push_back(d);
            }
        }
        int sum = 0;
        for (int i : v) {
            sum += i;
        }
        return sum;
    }
};