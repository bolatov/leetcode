class Solution {
private:
    bool isValid(int i, int mn, int mx) {
        return mn <= i && i < mx;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = !matrix.empty() ? matrix[0].size() : 0;
        //printf("m=%d, n=%d\n",m, n);
        vector<int> v;
        vector<pair<int, int>> dirs = {
            {0, 1}, // east
            {1, 0}, // south
            {0, -1}, // west
            {-1, 0} // north
        };
        
        vector<vector<bool>> mm(m, vector<bool>(n, 0));
        for (int i = 0, j = 0, dir = 0; isValid(i, 0, m) && isValid(j, 0, n) && !mm[i][j];) {
            //printf("%d ", matrix[i][j]);
            v.push_back(matrix[i][j]);
            mm[i][j] = 1;
            int inext = i + dirs[dir].first;
            int jnext = j + dirs[dir].second;
            if (isValid(inext, 0, m) && isValid(jnext, 0, n) && !mm[inext][jnext]) {
                i = inext;
                j = jnext;
            } else {
                dir++;
                dir %= dirs.size();
                
                i += dirs[dir].first;
                j += dirs[dir].second;
            }
        }
        
        return v;
    }
};
