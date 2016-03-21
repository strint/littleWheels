# Problem
88. Merge Sorted Array https://leetcode.com/problems/merge-sorted-array/

# Analysis

# Solution
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        auto p1 = nums1.begin();
        auto p2 = nums2.begin();
        while(p2 != nums2.end()) {
            //找到要插入的位置
            while(p1 != nums1.end() && *p2 > *p1) {
                ++p1;
            }
            //插入
            if(p1 == nums1.end()) {
                nums1.insert(p1, p2, nums2.end());
                p2 = nums2.end();
            } else {
                nums1.insert(p1, *p2);
                ++p2;
            }
        }
    }
};
```

# Notes
