# Problem
Remove Duplicates from Sorted Array

# Solution
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = nums.begin();
        int t, n;
        if(it != nums.end()) {
            t = *it;
        } else {
            return 0;
        }
        ++it;
        while( it != nums.end()) {
            n = *it;
            if(t == n) {
                it = nums.erase(it);
            } else {
                t = *it;
                ++it;
            }
        }
        return nums.size();
    }
};
```

# Notes
