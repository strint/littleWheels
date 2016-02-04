# Problem
 Remove Element

# Solution
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = nums.begin();
        int n;
        if(it != nums.end()) {
            n = *it;
            if(n == val) {
                it = nums.erase(it);
            } else {
                ++it;
            }
        } else {
            return 0;
        }
        while(it != nums.end()) {
            n = *it;
            if(n == val) {
                it = nums.erase(it);
            } else {
                ++it;
            }
        }
        return nums.size();
    }
};
```

# Notes
