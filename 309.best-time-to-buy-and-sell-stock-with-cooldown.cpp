/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0)  return 0;        
        int dp[n][2];
        int dp_pre=0,temp;
        for (int i = 0; i < n; i++) {
                if (i - 1 == -1) { 
                    dp[i][0]=0;
                    dp[i][1]=-prices[i];
                    temp=dp[i][0];
                    dp_pre=temp;
                    continue;
                    }
                temp=dp[i-1][0];
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
                dp[i][1] = max(dp[i-1][1], dp_pre - prices[i]);
                dp_pre=temp;
        }
        return dp[n - 1][0];
    }
};

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0)  return 0;        
        int dp_i_0=0,dp_i_1=INT_MIN;
        int dp_pre=0,temp;
        for (int i = 0; i < n; i++) {
              
                temp=dp_i_0;
                dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
                dp_i_1 = max(dp_i_1, dp_pre - prices[i]);
                dp_pre=temp;
        }
        return dp_i_0;
    }

    /* 同样的，类似于之前的股票问题， 在k的存在可以被省去的情况下，可以采用空间复杂度更低的
    单循环方法去解决此问题 不再使用一个数组而是使用一个两个迭代的数字去参与循环，但是请注意这两种
    编程模式中的basecase的确定问题 第一种代码格式将basecase置于循环之中，所以实际上需要计算出
    第一次（而不是第零次）的利润  而第二种代码格式则不需要计算，只需要给出第零次的参数即可 所以
    第一组代码在前一组的问题处理上要比第二组复杂，因为卖出股票后过一天才能重新买，所以必须要考虑
    前一天的情况，但是如果直接使用[i-2]则很容易造成超出数组范围的情况出现，所以重点在于需要加入
    一个前一天利润的记录点dp_pre，该点可以将本次循环中的卖出利润带入下一个循环，所以巧妙的解决了
    前一天利润的提取问题 */