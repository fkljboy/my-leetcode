/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
         int flag=nums[0];
         for (int i=1;i<nums.size();i++){
             if (nums[i]==flag) count++;
             else {
                 count--;
                 if (count==0) {
                     flag=nums[i];
                     count=1;
                 } 
             }
         }
        return flag;
    }
};
/*方法一 因为众数的数量一定是超过数组长度的一半的 这个设定有利于设计
令count=1 遍历数组中的元素 如果相等则count加一 反之count减一 count
为0则换一个数 由于众数过半 所以一定 可以通过这个方法找到
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
方法二也利用了这个性质 先对数组进行排序 然后取其中位数 一定就是众数