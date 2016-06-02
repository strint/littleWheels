# Problem
Longest Palindromic Substring

# Solution
```
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len <= 1) {
            return s;
        }
        int l, r, h = 0;
        int maxh = 0, ml = 0, mr = 0;
        //以i处的字符为中心
        for(int i = 0; i < len; ++i) {
            h = 1;
            l = i - h;
            r = i + h;
            while(l >= 0 && r < len && s[l] == s[r]) {
                ++h;
                l = i - h;
                r = i + h;
            }
            if(2 * h - 1 > maxh) {
                maxh = 2 * h - 1;
                ml = l + 1;
                mr = r - 1;
            }
        }
        //以i处和i+1处之间对称
        for(int i = 0; i < len; ++i) {
            h = 1;
            l = i - h + 1;
            r = i + h;
            while(l >= 0 && r < len && s[l] == s[r]) {
                ++h;
                l = i - h + 1;
                r = i + h;
            }
            if(2 * h - 2 > maxh) {
                maxh = 2 * h - 2;
                ml = l + 1;
                mr = r - 1;
            }
        }
        
        return s.substr(ml, mr - ml + 1);
    }
};
```

# Notes
