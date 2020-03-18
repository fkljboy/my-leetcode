/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int now=0;
        int maxmoney=0;
        for(int i=1;i<prices.size();++i)
        {
            now+=(prices[i]-prices[i-1]);
            maxmoney =max(now,maxmoney);
            now=max(0,now);
        }
        return maxmoney;
    }
};

/*动态规划问题 
   int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0) return 0;
        int dp[n][2];
        for (int i = 0; i < n; i++) {
            if (i - 1 == -1) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }
        return dp[n - 1][0];
    }
试着去理解什么叫“状态” 对于本题 状态有二 1.当前所在的天数
2.当前所处的状态  而我们要返回的值就是在最后一天且资金状态为
rest 的情况，然后将所有情况进行穷举，并通过max函数进行比较
对于状态转移函数，有两个情况 即资金状态为空仓和满仓，这时候
我们将每一天是空仓和满仓的所有情况全部都列出来，在其中找到
最大的一种情况，就是我们要寻找的值，同时这一天应该是最后一天。
