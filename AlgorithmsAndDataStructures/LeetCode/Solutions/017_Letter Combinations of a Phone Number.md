# Problem
17 Letter Combinations of a Phone Number https://leetcode.com/problems/letter-combinations-of-a-phone-number/

# Analysis

# Solution
```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.length() < 1) {
            return ret;
        }
        //每新来一个数字，假设可以产生x种字母，就把原来的每个字符串变成x个字符串
        ret.push_back("");
        for(int i = 0; i < digits.length(); ++i) {
            vector<string> temp;
            char c = digits[i];
            if('2' == c) {
                for(int j = 0; j < ret.size(); ++j) {
                    temp.push_back(ret[j] + "a");
                    temp.push_back(ret[j] + "b");
                    temp.push_back(ret[j] + "c");
                }
            } else if('3' == c) {
                for(int j = 0; j < ret.size(); ++j) {
                    temp.push_back(ret[j] + "d");
                    temp.push_back(ret[j] + "e");
                    temp.push_back(ret[j] + "f");
                }
            } else if('4' == c) {
                for(int j = 0; j < ret.size(); ++j) {
                    temp.push_back(ret[j] + "g");
                    temp.push_back(ret[j] + "h");
                    temp.push_back(ret[j] + "i");
                }
            } else if('5' == c) {
                for(int j = 0; j < ret.size(); ++j) {
                    temp.push_back(ret[j] + "j");
                    temp.push_back(ret[j] + "k");
                    temp.push_back(ret[j] + "l");
                }
            } else if('6' == c) {
                for(int j = 0; j < ret.size(); ++j) {
                    temp.push_back(ret[j] + "m");
                    temp.push_back(ret[j] + "n");
                    temp.push_back(ret[j] + "o");
                }
            } else if('7' == c) {
                for(int j = 0; j < ret.size(); ++j) {
                    temp.push_back(ret[j] + "p");
                    temp.push_back(ret[j] + "q");
                    temp.push_back(ret[j] + "r");
                    temp.push_back(ret[j] + "s");
                }
            } else if('8' == c) {
                for(int j = 0; j < ret.size(); ++j) {
                    temp.push_back(ret[j] + "t");
                    temp.push_back(ret[j] + "u");
                    temp.push_back(ret[j] + "v");
                }
            } else if('9' == c) {
                for(int j = 0; j < ret.size(); ++j) {
                    temp.push_back(ret[j] + "w");
                    temp.push_back(ret[j] + "x");
                    temp.push_back(ret[j] + "y");
                    temp.push_back(ret[j] + "z");
                }
            }
            ret = temp;
            temp.clear();
        }
        return ret;
    }
};
```

# Notes
