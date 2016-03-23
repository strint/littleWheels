# Problem
16 3Sum Closest https://leetcode.com/problems/3sum-closest/

# Analysis

# Solution
```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) {
            return 0;
        } 
        std::sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[nums.size() - 1];
        int mdis = std::abs(target - sum);
        int mt = sum;
        for(int i = 0; i < nums.size() - 2;) {
            int t = target  - nums[i];
            int s = i + 1;
            int e = nums.size() - 1;
            while(s < e) {
                sum = nums[s] + nums[e];
                int dis = abs(t - sum);
                if(dis < mdis){
                    mdis = dis;
                    mt = sum + nums[i];
                }
                if(sum < t) {
                    ++s;
                } else if(sum > t) {
                    --e;
                } else {
                    return target;
                }
            }
            ++i;
            while(i < nums.size() - 2 && nums[i - 1] == nums[i]) {
                ++i;
            }
        }
        return mt;
    }
};
```

# Notes
