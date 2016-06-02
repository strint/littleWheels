# Problem
125 Valid Palindrome https://leetcode.com/problems/valid-palindrome/

# Analysis

# Solution
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int p1, p2, len;
        len = s.length();
        p1 = 0;
        p2 = len - 1;
        char l, r;
        while(p1 < p2) {
            //移动到一个字符
            while(p1 < len && !((s[p1] >= 'a' && s[p1] <= 'z') || (s[p1] >= 'A' && s[p1] <= 'Z') || (s[p1] >= '0' && s[p1] <= '9'))) {
                ++p1;
            }
            while(p2 >= 0 && !((s[p2] >= 'a' && s[p2] <= 'z') || (s[p2] >= 'A' && s[p2] <= 'Z') || (s[p2] >= '0' && s[p2] <= '9'))) {
                --p2;
            }
            if((p1 < p2) && (p1 < len) && (p2 >= 0)) {
                if((s[p1] >= '0' && s[p1] <= '9') || (s[p2] >= '0' && s[p2] <= '9')) { //处理含有数字的情况
                    if(s[p1] == s[p2]) {
                        ++p1;
                        --p2;
                    } else {
                        return false;
                    }
                } else if(s[p1] == s[p2] || abs(s[p1] - s[p2]) == 32) {//处理两个都是字母的情况
                    ++p1;
                    --p2;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
```

# Notes
