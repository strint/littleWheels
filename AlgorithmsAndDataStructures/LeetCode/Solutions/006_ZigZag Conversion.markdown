# Problem
ZigZag Conversion

# Solution
```
class Solution {
public:
    string convert(string s, int numRows) {
        string sr = "";
        vector<string> vs(numRows);
        
        if(numRows == 1) {
            //一行时，直接返回
            return s;
        } else if(numRows == 2) {
            //两行时，Z字没有中间的斜线
            for(int i = 0; i < s.size(); ++i) {
                vs[i % 2].push_back(s[i]);
            }
        } else {
            int g = numRows * 2 - 2;
            int j = 0;
            for(int i = 0; i < s.size(); ++i) {
                j = i % g;
                if(j < numRows) {
                    vs[j].push_back(s[i]); //竖线
                } else {
                    vs[g - j].push_back(s[i]); //斜线
                }
            }
        }
        //各行拼接成一个字符串
        for(int k = 0; k < vs.size(); ++k) {
            sr += vs[k];
        }
        
        return sr;
    }
};
```

# Notes
* 知道zigzag的[样式](https://leetcode.com/discuss/55208/if-you-are-confused-with-zigzag-pattern-come-and-see)
```
/*n=numRows
Δ=2n-2    1                           2n-1                         4n-3
Δ=        2                     2n-2  2n                    4n-4   4n-2
Δ=        3               2n-3        2n+1              4n-5       .
Δ=        .           .               .               .            .
Δ=        .       n+2                 .           3n               .
Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
Δ=2n-2    n                           3n-2                         5n-4
*/
```
* 添加对nunRows等于1、2时的处理办法
