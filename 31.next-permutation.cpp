/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int j = nums.size() - 1; 
        while(j-1>=0 && nums[j-1] >= nums[j]){ --j;}
        if(j == 0){
            for(int i = 0; i < nums.size()/2; ++i){
                swap(nums[i], nums[nums.size() - 1 - i]);
            }
            return ;
        }
        int r = nums.size() - 1;
        while(r >= j){
            if(nums[r] > nums[j-1]) break;
            --r;
        }
        swap(nums[r], nums[j-1]);
        int cnt = (nums.size() - j)/2;
        int i = 0;
        while(cnt > 0){
            swap(nums[j+i], nums[nums.size() - 1 - i]);
            ++i; --cnt;
        }
        return;
    }
};
/*判断按照字典序有木有下一个，如果完全降序就没有下一个
如何判断有木有下一个呢？只要存在a[i-1] < a[i]的升序结构，
就有，而且我们应该从右往左找，一旦找到，因为这样才是真正下一个
当发现a[i-1] < a[i]的结构时，从在[i, ∞]中找到最接近a[i-1]
并且又大于a[i-1]的数字，由于降序，从右往左遍历即可得到k
然后交换a[i-1]与a[k]，然后对[i, ∞]排序即可，排序只需要首尾不停交换即可，
因为已经是降序 上面说的很抽象，还是需要拿一些例子思考才行，比如[0,5,4,3,2,1]，
下一个是[1,0,2,3,4,5]
总结一下 就是首先需要找到第一组前一个数比下一个数小的树，然后从这个数开始
找到比他大的最小的一个数，二者交换位置，之后将该数后面的所有数升序排列，因为
我们是从右往左找的，所以可以确定我们确定了那个数只有，右边的所有数都是降序排列
的
// @lc code=end

