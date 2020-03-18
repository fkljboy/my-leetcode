/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int MAX=nums[0]+nums[1]+nums[2];
        for (int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
            int sum=nums[i]+nums[left]+nums[right];
            if (abs(target-sum)<abs(MAX-target))
                MAX=sum;
              if(sum > target)
                    right--;
                else if(sum < target)
                    left++;
                else
                    return MAX;

            }
        }
        return MAX;
    }
};
/*常规的双指针解法
// @lc code=end

