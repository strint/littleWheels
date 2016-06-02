# Problem
63 Unique Paths II https://leetcode.com/problems/unique-paths-ii/

# Analysis

# Solution
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int c = obstacleGrid.size();
        int r;
        if(c > 0) {
            r = obstacleGrid[0].size();
        }
        if(0 == c || 0 == r) {
            return 0;
        }
        int M[c][r];
        if(1 == obstacleGrid[0][0]) {
            return 0;
        }
        M[0][0] = 1;
        for(int i = 1; i < r; ++i) {
            if(obstacleGrid[0][i] == 0) {
                M[0][i] = M[0][i - 1];
            } else {
                M[0][i] = 0;
            }
        }
        for(int j = 1; j < c; ++j) {
            if(obstacleGrid[j][0] == 0) {
                M[j][0] = M[j - 1][0];
            } else {
                M[j][0] = 0;
            }
        }
        for(int k = 1; k < c; ++k) {
            for(int l = 1; l < r; ++l) {
                if(obstacleGrid[k][l] == 0) {
                    M[k][l] = M[k - 1][l] + M[k][l - 1];
                } else {
                    M[k][l] = 0;
                }
            }
        }
        return M[c - 1][r - 1];
    }
};
```

# Notes
