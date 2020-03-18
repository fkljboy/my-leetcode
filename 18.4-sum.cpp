/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for (int j=0;j<n-3;j++){
            if(j>0&&nums[j]==nums[j-1]) continue;  //跳过无意义的移动
            for (int i=j+1;i<n-2;i++){
            //if (nums[i]>0) break;
                if (i>j+1&&nums[i]==nums[i-1]) continue;  //跳过无意义的移动 注意i的判断起始位置
                int left=i+1;
                int right=n-1;
                while(left<right){
            //if (nums[i]<0&&nums[right] < 0) break;
                int sum=nums[j]+nums[i]+nums[left]+nums[right];
                if (sum>target) right--;
                else if (sum<target) left++;
                else  {
                    res.push_back({nums[j],nums[i],nums[left],nums[right]});
                    while(left<right&&nums[left]==nums[left+1])      //跳过无意义移动
        			    left++;
        			while(left<right&&nums[right]==nums[right-1])      //同上
        			    right--;
        			left++;
        			right--; 

            }
            }
        }
        }
        return res;
    }
};
// @lc code=end

/*四数相加问题和三数相加问题的解法套路是一样的 只需要加一重循环，将前两个数固定 然后依旧双指针，然后依次移动固定好的指针
进行循环就可以 区别在于，必须要严格考虑因为多了一重循环而导致的部分参数的微调 比如在第二重循环中，要使第二个固定点永远从
第一个固定点的右侧第一个开始算起，为避免重复必须要同时考虑四个指针的重复跳过问题 