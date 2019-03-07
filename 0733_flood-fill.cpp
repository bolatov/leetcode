class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> u(image.size(), vector<bool>(image[0].size(), false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int oldColor = image[sr][sc];
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int r = p.first, c = p.second;
            if (u[r][c] || oldColor != image[r][c]) continue;
            u[r][c] = true;
            image[r][c] = newColor;
            if (r - 1 >= 0              && !u[r - 1][c]) q.push({r - 1, c});
            if (r + 1 < image.size()    && !u[r + 1][c]) q.push({r + 1, c});
            if (c - 1 >= 0              && !u[r][c - 1]) q.push({r, c - 1});
            if (c + 1 < image[0].size() && !u[r][c + 1]) q.push({r, c + 1});
        }
        return image;
    }
};
