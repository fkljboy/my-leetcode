/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int s=0;
        while (i<j){
            s=max(s,min(height[i],height[j])*(j-i));
            if (height[i]>height[j])
            j--;
            else 
            i++;
        }
        return s;
    }
};
/*双指针法// @lc code=end

