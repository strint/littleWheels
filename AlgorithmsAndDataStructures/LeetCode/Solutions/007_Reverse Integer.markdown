# Problem
Reverse Integer

# Solution
```
class Solution {
public:
    int reverse(int x) {
        long long r = 0; //解决计算中的溢出问题
        int s = 1;
        int d = 0;
        
        if(x < 0) {
            s = -1;
            x = -x;
        }
        
        while(x > 0) {
            d = x - (x / 10) * 10;
            r = r * 10 + d;
            x /= 10;
        }
        
        if(s == -1) {
            r = -r;
        }
        //input为1534236469时，r值为9*********，而int的最大正值为2147483647，所以会上溢出
        //input为-1563847412时，r值为-2147483651，而int的最小负值为-2147483647，所以会下溢出
        
        //处理溢出问题
        if(r > INT_MAX || r < INT_MIN) {
            return 0;
        } else {
            return r;
        }
    }
};
```

# Notes
* 需要处理int溢出的情况
