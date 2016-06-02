# Problem
 Implement strStr()

# Analysis

# Solution
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if(n == 0) {
            return 0;
        }
        if(m == 0 || n == 0) {
            return -1;
        }
        int p = 0;
        for(int i = 0; i < (m - n + 1); ++i) { //这里-n可以减少运行时间
            p = 0;
            while((p < n) && ((i + p) < m)) {
                if(needle.at(p) == haystack.at(i + p)) {
                    ++p;
                } else {
                    break;
                }
            }
            if(p == n) {
                return i;
            }
        }
        return -1;
    }
};
```

# Notes
