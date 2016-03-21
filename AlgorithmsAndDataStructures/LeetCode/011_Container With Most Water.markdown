# Problem
Container With Most Water

# Analysis
* 有宽高两个变量，求宽高乘积最大。
* 没法按照高递减来遍历；
* 可以按照宽递减来遍历，这时要求高必须变大。从而减少时间复杂度。

# Solution
```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if(len <= 1) {
            return 0;
        }
        int max, h, maxh, s, l, r;
        max = 0;
        l = 0;
        r = len - 1;
        while(l < r) {
            //计算当前的面积
            h = min(height[l], height[r]);
            s = h * (r - l);
            if(s > max) {
                max = s;
                maxh = h;
            }
            //找到下一组高度够大的容器
            while(height[l] <= h) {
                ++l;
            }
            while(height[r] <= h) {
                --r;
            }
        }
        
        return max;
    }
};
```

