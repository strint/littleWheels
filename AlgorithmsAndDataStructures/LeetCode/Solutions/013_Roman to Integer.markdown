# Problem
Roman to Integer，罗马数字转为整数

# Solution
```
class Solution {
public:
    int romanToInt(string s) {
        vector<int> n;
        for(int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if('I' == c) {
                n.push_back(1);
            } else if('V' == c) {
                n.push_back(5);
            } else if('X' == c) {
                n.push_back(10);
            } else if('L' == c) {
                n.push_back(50);
            } else if('C' == c) {
                n.push_back(100);
            } else if('D' == c) {
                n.push_back(500);
            } else if('M' == c) {
                n.push_back(1000);
            }
        }
        int r = 0;
        n.push_back(-1); //保证下面的循环中的比较在最后一个数字也能进行
        for(int j = 0; j < n.size() - 1; ++j) {
            if(n[j] < n[j + 1]) {
                r -= n[j];
            } else {
                r += n[j];
            }
        }
        return r;
    }
};
```

# Notes
* 主要是知道罗马数字的表示方法中，数字从大到小排列，如果有反的，则这一对反的是一个对，直接把这一对中前面那个取负值就好了
