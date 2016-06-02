# Problem
22 Generate Parentheses https://leetcode.com/problems/generate-parentheses/

# Analysis
* f(n) = (f(0))f(n-1) + (f(1))f(n-2) + ... + (f(n-2))f(1) + (f(n-1))f(0).
* ref: https://leetcode.com/discuss/11509/an-iterative-method
# Solution
```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > formerRes;
        vector<string> ret;
        if(0 == n) {
            return ret;
        }
        ret.push_back("");
        formerRes.push_back(ret);
        ret.clear();
        ret.push_back("()");
        if(1 == n) {
            return ret;
        }
        formerRes.push_back(ret);
        // f(n) = (f(0))f(n-1) + (f(1))f(n-2) + ... + (f(n-2))f(1) + (f(n-1))f(0).
        // ref: https://leetcode.com/discuss/11509/an-iterative-method
        for(int i = 2; i <= n;  ++i) {
            ret.clear();
            for(int j = 0; j <= i - 1; ++j) {
                int l = j;
                int r = i - 1 -j;
                for(int k = 0; k < formerRes[l].size(); ++k) {
                    string ls = "(" + formerRes[l][k] + ")"; 
                    for(int m = 0; m < formerRes[r].size(); ++m) {
                        string rs = formerRes[r][m];
                        ret.push_back(ls + rs);
                    }
                }
            }
            formerRes.push_back(ret);
        }
        return ret;
    }
};
```

# Notes
