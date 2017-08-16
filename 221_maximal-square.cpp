class Solution {
private:
    int area(int n) {
        return n * n;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    ans = max(ans, 1);
                    bool success = true;
                    for (int layer = 1; success && i + layer < rows && j + layer < cols; layer++) {
                        for (int col = j; col <= j + layer; col++) {
                            if (matrix[i + layer][col] != '1') {
                                success = false;
                                break;
                            }
                        }   
                        
                        for (int row = i; success && row <= i + layer; row++) {
                            if (matrix[row][j + layer] != '1') {
                                success = false;
                                break;
                            }
                        }
                        
                        if (!success) {
                            break;
                        }
                        ans = max(ans, area(layer + 1));
                    }
                }
            }
        }
        return ans;
    }
};
