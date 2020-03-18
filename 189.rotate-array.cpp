/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());


    }
};

/*直接调用c++标准库的reverse函数，就可以实现原地掉头的过程这个方法基于这个事实：当我们旋转数组 k 次， 
k\%nk%n 个尾部元素会被移动到头部，剩下的元素会被向后移动。在这个方法中，我们首先将所有元素反转。
然后反转前 k 个元素，再反转后面 n-kn−k 个元素，就能得到想要的结果
