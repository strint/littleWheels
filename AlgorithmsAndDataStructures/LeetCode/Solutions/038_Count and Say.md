# Problem
Count and Say https://leetcode.com/problems/count-and-say/

# Analysis

# Solution
```
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        } else {
            string now = "1";
            string next = "";
            int count = 0;
            for(int i = 2; i <= n; ++i) {
                //根据now计算next
                now.push_back(0);//处理结尾，0一定与之前的字符一定不同，使得最后一组数字可以得到保存
                next = "";
                for(int j = 0; j < now.length(); ++j) {
                    if(j == 0) {
                        ++count;
                    } else {
                        if(now.at(j) == now.at(j - 1)) {
                            ++count;
                        } else {
                            next.push_back('0' + count); //由int得到char的方法
                            next.push_back(now.at(j - 1));
                            count = 1;
                        }
                    }
                }
                now = next;
                count = 0;
            }
            return now;
        }
    }
};
```

# Notes
