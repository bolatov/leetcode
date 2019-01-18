// Updated. Solved by following the "Explore Queue & Stack" tutorial
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return node;
        }
        unordered_map<int, UndirectedGraphNode*> mp;
        stack<UndirectedGraphNode*> st;
        st.push(node);
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            mp[top->label] = mp.count(top->label) ? mp[top->label] : new UndirectedGraphNode(top->label);
            for (auto nb : top->neighbors) {
                auto nbCopy = mp.count(nb->label) ? mp[nb->label] : new UndirectedGraphNode(nb->label);
                if (!mp.count(nb->label)) {
                    st.push(nb);
                }
                mp[top->label]->neighbors.push_back(nbCopy);
                mp[nb->label] = nbCopy;
            }
        }
        return mp[node->label];
    }
};

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return node;
        }
        
        // Create shallow copies of each node in the graph
        
        unordered_map<int, UndirectedGraphNode*> mp;
        unordered_set<int> visited;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            if (visited.count(f->label)) continue;
            visited.insert(f->label);
            mp[f->label] = new UndirectedGraphNode(f->label);
            for (auto nb : f->neighbors) {
                if (!visited.count(nb->label)) {
                    q.push(nb);
                }
            }
        }
        
        // Add neighbors to each shallow copy
        
        visited.clear();
        q.push(node);
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            if (visited.count(f->label)) continue;
            visited.insert(f->label);
            for (auto nb : f->neighbors) {
                mp[f->label]->neighbors.push_back(mp[nb->label]);
                if (!visited.count(nb->label)) {
                    q.push(nb);
                }
            }
        }
        
        return mp[node->label];
    }
};
