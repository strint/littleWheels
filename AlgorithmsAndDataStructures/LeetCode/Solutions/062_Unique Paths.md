# Problem
62 Unique Paths https://leetcode.com/problems/unique-paths/

# Analysis
* 动态规划
* 找到最优子结构，找到递归公式
* 采用自顶向下时，深度优先时，要带备忘；采用自底向上时，可以得到递归解

# Solution
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 1 || n <= 1) {
            return 1;
        }
        int M[m][n];
        for(int i = 0; i < n; ++i) {
            M[0][i] = 1;
        }
        for(int j = 0; j < m; ++j) {
            M[j][0] = 1;
        }
        for(int k = 1; k < m; ++k) {
            for(int l = 1; l < n; ++l) {
                M[k][l] = M[k - 1][l] + M[k][l - 1];
            }
        }
        return M[m - 1][n - 1];
    }
};
```

# Notes
