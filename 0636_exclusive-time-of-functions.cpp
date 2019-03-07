class Solution {
private:
    const char MID = 'm';
    const char END = 'e';
public:
//     void printStack(stack<pair<int, pair<char, int>>> st, string s) {
//         while (!st.empty()) {
//             auto top = st.top();
//             st.pop();
//             printf("%s %d %c %d\n", s.c_str(), top.first, top.second.first, top.second.second);
//         }
//         puts("");
//     }
    
//     void printVector(vector<int>& vi) {
//         for (int i : vi) {
//             printf("%d ", i);
//         }
//         puts("");
//     }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> vi(n, 0);
        stack<pair<int, pair<char, int>>> st;
        for (string log : logs) {
            // cout << log << endl;
            // printStack(st, "");
            size_t p1 = log.find(":");
            int id = stoi(log.substr(0, p1));
            
            size_t p2 = log.find(":", p1 + 1);
            char ch = log[p1 + 1];
            
            int time = stoi(log.substr(p2 + 1));
            
            if (ch == END) {
                int subtime = 0;
                while (st.top().second.first == MID) {
                    auto top = st.top();
                    st.pop();
                    subtime += top.second.second;
                }
                auto top = st.top();
                st.pop();
                int dur = time - subtime - top.second.second + 1;
                vi[id] += dur;
                st.push({id, {MID, dur + subtime}});
            } else {
                st.push({id, {ch, time}});
            }
            // printStack(st, "\t");
            // printVector(vi);
            // puts("---------------------------------");
        }
        return vi;
    }
};
