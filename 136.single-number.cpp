/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int n=nums.size();
        if (n==1) return nums[0];
        sort(nums.begin(),nums.begin()+n);
        if (nums[0]!=nums[1]) return nums[0];
        if (nums[n-1]!=nums[n-2]) return nums[n-1];
        for(int i=1;i<n-1;i++)
        {
            if (nums[i]!=nums[i+1]&&nums[i]!=nums[i-1]) return nums[i];
        }
        return 0;
    }
};
/* 这道题我的思路是先排序，排序所有重复的数都会集中在一起，在集中以后
首先判断收尾两个位置的值 如果和第二个及倒数第二个不一样则直接返回，然后
对其余部分进行遍历 找出和左右都不相等的位置即为所求值
方法二：异或算法
只要存在重复的数字，则在异或运算中无论是否存在间隔都会得到运算结果0
所以程序可以写为
int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        for(int i=0;i<n;i++)
        {
            nums[i]=a^num[i];
        }
        return num[i];
    }
通过迭代的异或运算 最后没有归零的一个数即为落单的数
方法三：哈希表方法 使用stl库中的set容器构建哈希表，如果第一次出现则
存入哈希表，如第二次出现则将其在哈希表中删除（利用set.count()和set.erase()
函数实现，
 int singleNumber(vector<int>& nums) {
        unordered_set<int> bobo;
        int ans;
        for(auto i : nums){
            if(bobo.count(i))   bobo.erase(i);
            else    bobo.insert(i);
        }
        for(auto j : bobo)  ans = j;
        return ans;
