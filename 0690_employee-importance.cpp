/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> mp;
        for (auto e : employees) mp[e->id] = e;
        
        int val = 0;
        queue<Employee*> q;
        q.push(mp[id]);
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            val += f->importance;
            for (int sub : f->subordinates) {
                q.push(mp[sub]);
            }
        }
        return val;
    }
};
