class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ans;
        if (n == 0) {
            return {};
        } else if (n <= 2) {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
            return ans;
        }
        
        // Build a graph
        vector<vector<int>> g(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto edge : edges) {
            g[edge.first].push_back(edge.second);
            g[edge.second].push_back(edge.first);
            degree[edge.first]++;
            degree[edge.second]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        while (n > 2) {
            int size = q.size();
            while(size--) {
                int cur = q.front();
                n--;
                q.pop();
                for (int child : g[cur]) {
                    degree[child]--;
                    if (degree[child] == 1) {
                        q.push(child);
                    }
                }
            }            
        }
        
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

/*
TEST CASES
0
[]
1
[]
2
[[0,1]]
3
[[0,1],[0,2]]
4
[[1, 0], [1, 2], [1, 3]]
6
[[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
15
[[0,1],[0,2],[2,3],[2,4],[2,5],[4,6],[0,7],[4,8],[5,9],[7,10],[6,11],[0,12],[0,13],[3,14]]
84
[[0,1],[1,2],[2,3],[1,4],[0,5],[0,6],[6,7],[0,8],[1,9],[7,10],[8,11],[5,12],[8,13],[13,14],[5,15],[14,16],[10,17],[13,18],[16,19],[14,20],[8,21],[8,22],[16,23],[1,24],[15,25],[11,26],[9,27],[17,28],[26,29],[27,30],[17,31],[0,32],[31,33],[33,34],[33,35],[16,36],[17,37],[0,38],[34,39],[27,40],[37,41],[38,42],[21,43],[17,44],[20,45],[17,46],[40,47],[45,48],[39,49],[11,50],[25,51],[3,52],[23,53],[47,54],[43,55],[28,56],[11,57],[52,58],[20,59],[48,60],[37,61],[11,62],[43,63],[36,64],[64,65],[53,66],[14,67],[47,68],[61,69],[25,70],[5,71],[25,72],[23,73],[51,74],[25,75],[43,76],[35,77],[38,78],[66,79],[53,80],[67,81],[6,82],[82,83]]
*/
