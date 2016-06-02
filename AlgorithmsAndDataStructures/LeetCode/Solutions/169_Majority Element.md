# Problem
169 Majority Element https://leetcode.com/problems/majority-element/

# Analysis
https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm

# Solution
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candi = -1, vote = 1;//设置一个伪数据，这样能写成循环不变式
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            if(candi == nums[i]) {
                ++vote;
            } else {
                --vote;
                if(0 == vote) {
                    candi = nums[i];
                    vote = 1;
                }
            }
        }
        return candi;
    }
};
```

# Notes
