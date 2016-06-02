# Problem
Length of Last Word https://leetcode.com/problems/length-of-last-word/

# Analysis

# Solution
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.length();
        //从末尾到开头找到第一个非空格的字符
        int e = l - 1;
        while(e >= 0) {
            if(s.at(e) == ' ') {
                --e;
            } else {
                break;
            }
        }
        if(e == -1) {
            return 0; //全是空格
        } else {
            int p = e - 1;
            while(p >=0 && s[p] != ' ') {
                --p;
            }
            return e - p;
        }
    }
};
```

# Notes
