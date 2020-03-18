/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (42.41%)
 * Total Accepted:    1.6M
 * Total Submissions: 3.7M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int flag =0 ;
        vector<int> a;
        int num= nums.size();
        for (int i=0;i<num;i++){
            for(int j=i+1;j<num;j++){
                if(nums[i]+nums[j]==target)
                {
                    flag = 1 ;
                    a.push_back(i);
                    a.push_back(j);
                    return a;
                }
                   
            }
        }
        if (flag==0)
        throw ("the two num we search does not exist ");
        return a;
    }
};
//总结：在vector定义的方法中不能使用普通的数组而只能使用vector数组作为返回值，想数字赋给vector的
//方法是 a.push_back()   如果不能检查出存在需要的两个数 则可以用异常抛出函数 throw
