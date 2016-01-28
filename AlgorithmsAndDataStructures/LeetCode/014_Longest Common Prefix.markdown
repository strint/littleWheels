# Problem
Longest Common Prefix（字符串的共同的最长前缀字符串）

# Solution
```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        } else {
            string commPref = strs.at(0);
            string tempStr = "";
            string tempComm = "";
            for(int i = 1; i < strs.size(); ++i) {
                tempStr = strs.at(i);
                tempComm = "";
                for(int j = 0; (j < commPref.size()) && (j < tempStr.size()); ++j) {
                    if(commPref.at(j) == tempStr.at(j)) {
                        tempComm += commPref.at(j);
                    } else {
                        break; //如果同位置遇到不同的字符，就不再往后比较了
                    }
                }
                if(tempComm == "") {
                    return ""; //如果当前的共同前缀为空的话，就不用往后比较了
                } else {
                    commPref = tempComm;
                }
            }
            return commPref;
        }
    }
};
```

# Notes
* 简单的优化：存在循环可以提前停止的情况
