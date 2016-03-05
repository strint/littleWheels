# Problem
Longest Substring Without Repeating Characters，最长的的没有重复字符的子字符串

# Solution
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) {
            return 0;
        }
        map<char, int> charSet;
        int maxL = 1;
        int tempL = 1;
        int l = 0;
        charSet[s.at(0)] = 0;
        for(int i = 1; i < s.length(); ++i) {
            char c = s.at(i);
            auto search = charSet.find(c);
            if(search != charSet.end() && search->second >= l) {
                tempL = i - l;
                if(tempL > maxL) {
                    maxL = tempL;
                }
                l = search->second + 1;
            }
            charSet[c] = i;
        }
        tempL = s.length() - l;
        if(tempL > maxL) {
            maxL = tempL;
        }
        return maxL;
    }
};
```

# Notes
