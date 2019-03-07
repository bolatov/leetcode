class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, long long> mp;
        for (string s : cpdomains) {
            // split by space
            int i = s.find(" ");
            long long cnt = stoll(s.substr(0, i));
            string domain = s.substr(i + 1, s.size() - (i + 1));
            vector<string> domains = {domain};
            
            i = domain.find(".");
            while (i != string::npos) {
                domain = domain.substr(i + 1, domain.size() - (i + 1));
                domains.push_back(domain);
                i = domain.find(".");
            }
            
            for (string dom : domains) {
                if (mp.find(dom) == mp.end()) {
                    mp[dom] = cnt;
                } else {
                    mp[dom] += cnt;
                }
            }
        }
        
        vector<string> vs;
        for (auto kv : mp) {
            string s = to_string(kv.second) + " " + kv.first;
            vs.push_back(s);
        }
        return vs;
    }
};