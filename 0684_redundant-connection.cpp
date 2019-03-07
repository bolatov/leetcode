class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(), pv, pu, u, v;
        int uhops, vhops;
        vector<int> vi(n);
        for (int i = 0; i < n; i++) {vi[i] = i;}
        for (auto edge : edges) {
            u = edge[0] - 1;
            v = edge[1] - 1;
            
            uhops = 0;
            vhops = 0;
            
            // find a bag that vertex 'u' belongs to
            for (pu = u; vi[pu] != pu; pu = vi[pu]) uhops++; 
            
            // find a bag that vertex 'v' belongs to
            for (pv = v; vi[pv] != pv; pv = vi[pv]) vhops++;
            
            // check if vertices 'u' & 'v' already belong
            // to the same bag
            if (pu == pv) return edge;  
            
            if (uhops < vhops)  vi[pv] = pu;
            else                vi[pu] = pv;
        }
        return {};
    }
};
