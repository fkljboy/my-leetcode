/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for (int i=0;i<n-2;i++){
            if (nums[i]>0) break;
            if (i>0&&nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=n-1;
            while(left<right){
            if (nums[i]<0&&nums[right] < 0) break;
            int sum=nums[i]+nums[left]+nums[right];
            if (sum>0) right--;
            else if (sum<0) left++;
            else  {
                res.push_back({nums[i],nums[left],nums[right]});
                while(left<right&&nums[left]==nums[left+1])      //跳过无意义移动
        			    left++;
        			while(left<right&&nums[right]==nums[right-1])      //同上
        			    right--;
        			left++;
        			right--; 

            }
        }
        }
        return res;
    }
};
/* 先将给定 nums 排序，复杂度为 O(NlogN)O(NlogN)。
双指针法思路： 固定 33 个指针中最左（最小）数字的指针 k，双指针 i，j 分设在数组索引 (k, len(nums))(k,len(nums)) 两端，
通过双指针交替向中间移动，记录对于每个固定指针 k 的所有满足 nums[k] + nums[i] + nums[j] == 0 的 i,j 组合：
当 nums[k] > 0 时直接break跳出：因为 nums[j] >= nums[i] >= nums[k] > 0，即 33 个数字都大于 00 ，在此固定指针 k 之后不可能再找到结果了。
当 k > 0且nums[k] == nums[k - 1]时即跳过此元素nums[k]：因为已经将 nums[k - 1] 的所有组合加入到结果中，本次双指针搜索只会得到重复组合。
i，j 分设在数组索引 (k, len(nums))(k,len(nums)) 两端，当i < j时循环计算s = nums[k] + nums[i] + nums[j]，加入判断
三个数是不是都小于零，若都小于零则break；并按照以下规则执行双指针移动：
当s < 0时，i += 1并跳过所有重复的nums[i]；
当s > 0时，j -= 1并跳过所有重复的nums[j]；
当s == 0时，记录组合[k, i, j]至res，执行i += 1和j -= 1并跳过所有重复的nums[i]和nums[j]，防止记录到重复组合

// @lc code=end

