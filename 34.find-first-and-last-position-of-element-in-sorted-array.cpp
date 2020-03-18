class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res={-1,-1};
        int n=nums.size();
        for(int i=0;i<n;i++){
            if (nums[i]==target) {
                res[0]=i;
                break;
            }
        }
        for(int j=n-1;j>=0;j--){
            if (nums[j]==target) 
            {
                res[1]=j;
                break;
            }
        }
        return res;
    }
};
/* 这是本题的c++解法，通过两次扫描 一次前向扫描一次逆向扫描，前向扫描
可以找出第一项target而后向扫描可以找到后面的第一项也就是最后一项target
将两个坐标记录下来即可