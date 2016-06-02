# Problem
34 Search for a Range

# Analysis

# Solution
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        int len = nums.size();
        int l = 0, r = len - 1, m, n;
        bool finded = false;
        while(l <= r) { //二分查找的标准写法，注意这里是<=，这样可以处理l==r的情况
            m = (l + r) / 2;
            n = nums.at(m);
            if(n < target) {
                l = m + 1;
            } else if(n > target) {
                r = m - 1;
            } else {
                finded = true;
                break;
            }
        }
        if(!finded) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        } else {
            l = m;
            r = m;
            while(l - 1 >= 0 && nums[l -1] == target) {
                --l;
            }
            while(r + 1 < len && nums[r + 1] == target) {
                ++r;
            }
            ret.push_back(l);
            ret.push_back(r);
            return ret;
        }
    }
};
```

# Notes
