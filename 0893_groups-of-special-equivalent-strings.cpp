class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> st;
        for (string a : A) {
            vector<char> v, u;
            for (int i = 0; i < a.size(); i++) {
                if (i % 2) v.push_back(a[i]);
                else u.push_back(a[i]);
            }
            sort(v.begin(), v.end());
            sort(u.begin(), u.end());
            int iv = 0, iu = 0;
            string s = "";
            for (int i = 0; i < a.size(); i++) {
                if (i % 2) s += v[iv++];
                else s += u[iu++];
            }
            // printf("%s --> %s\n", a.c_str(), s.c_str());
            st.insert(s);
        }
        return st.size();
    }
};
