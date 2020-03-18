/*
 * @lc app=leetcode id=33 lang=java
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
    public int search(int[] nums, int target) {
        int[] res={-1,-1};
        int n=nums.length;
        for (int i=0;i<n;i++){
            if(nums[i]==target){
                res[0]=i;
                break;
            }
        }
        if(res[0]==-1) return res;
        for (int j=n-1;j>=0;j--){
            if(nums[j]==target){
                res[1]=j;
                break;
            }
        
        }
        return res;
    }
}

/* java 的语法和c++十分类似,只有部分的函数不一样而已*/
// @lc code=end

class Solution {
    // returns leftmost (or rightmost) index at which `target` should be
    // inserted in sorted array `nums` via binary search.
    private int extremeInsertionIndex(int[] nums, int target, boolean left) {
        int lo = 0;
        int hi = nums.length;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || (left && target == nums[mid])) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }

        return lo;
    }

    public int[] searchRange(int[] nums, int target) {
        int[] targetRange = {-1, -1};

        int leftIdx = extremeInsertionIndex(nums, target, true);

        // assert that `leftIdx` is within the array bounds and that `target`
        // is actually in `nums`.
        if (leftIdx == nums.length || nums[leftIdx] != target) {
            return targetRange;
        }

        targetRange[0] = leftIdx;
        targetRange[1] = extremeInsertionIndex(nums, target, false)-1;

        return targetRange;
    }
}

/*二分法是这道题时间复杂度更低的一种解法 二分法的实现很简单 ，但是具体的实现在
这道题目中是需要操作的，首先在找到一个target以后不能停止搜索，而是要继续搜索
直到low和high指针重合  第二是我们要通过一个参数来确定应该向左搜索还是向右搜索
需要在找左边的target的时候向左搜索而需要找右边的时候向右搜索， */
