# Problem
29 Divide Two Integers https://leetcode.com/problems/divide-two-integers/

# Analysis

# Solution
```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        //处理几种可能越界的情况
        if(0 == divisor) {
            return INT_MAX;
        } else if(0 == dividend) {
            return 0;
        } else if(INT_MIN == dividend && 1 == divisor) {
            return INT_MIN;
        } else if(INT_MIN == dividend && -1 == divisor) {
            return INT_MAX;
        }
        typedef long long ll;
        ll dd = dividend;
        ll ds = divisor;
        int sign = ((dd > 0 && ds > 0) || (dd < 0 && ds < 0)) ? 1 : -1;
        dd = labs(dd);
        ds = labs(ds);
        ll count;
        ll dis;
        ll did = dd;
        ll ans = 0;
        while(did > 0) {
            dis = ds;
            if(did - ds >= 0) {
                count = 1;
            } else {
                count = 0;
            }
            while( did - dis >= dis) {
                //使用bit的左移操作，加快减法，以指数速度逼近被除数，时间复杂度为log(n)，空间复杂度为常数
                dis <<= 1;
                count <<= 1;
            }
            did -= dis;
            ans += count;
        }
        return sign * ans;
    }
};
```

# Notes
