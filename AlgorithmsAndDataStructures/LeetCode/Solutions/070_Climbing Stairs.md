# Problem
70. Climbing Stairs https://leetcode.com/problems/climbing-stairs/

# Analysis

# Solution
```
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 0) {
            return 1;
        } else if(n == 2) {
            return 2;
        } else if(n >= 3) {
            int n1, n2, n0;
            n2 = 1;
            n1 = 2;
            for(int i = 3; i <= n; ++i) {
                n0 = n1 + n2;
                n2 = n1;
                n1 = n0;
            }
            return n0;
        }
    }
};
```

# Notes
