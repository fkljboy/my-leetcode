/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_k = 2;
        int n = prices.size();
        if (n==0)  return 0;        
        int dp[n][max_k + 1][2];
        for (int i = 0; i < n; i++) {
            for (int k = max_k; k >= 1; k--) {
                if (i - 1 == -1) { 
                    dp[i][k][0]=dp[i][0][0]=0;
                    dp[i][k][1]=dp[i][0][1]=-prices[i];
                    continue;
                    }
                if (k-1==0) dp[i][k-1][0]=0;
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        }
        return dp[n - 1][max_k][0];

    }
};

/*int maxProfit(vector<int>& prices) {
        int n=prices.size();
      int dp_i10 = 0, dp_i11 = INT_MIN;
    int dp_i20 = 0, dp_i21 = INT_MIN;
    for (int i=0;i<n;i++) {
        dp_i20 = max(dp_i20, dp_i21 + prices[i]);
        dp_i21 = max(dp_i21, dp_i10 - prices[i]);
        dp_i10 = max(dp_i10, dp_i11 + prices[i]);
        dp_i11 = max(dp_i11, -prices[i]);
    }
    return dp_i20;
}
由于只有两种情况，k=0和k=1，所以可以绕开对k的循环，直接列举四种状态的转移
从四种状态中找到最大值即可，如果选择列举的方法，则basecase也会参与到全局的
遍历中去，这种情况只需将i=0 的情况按实际情况设置即可 则可知在i=0且持有股票
时的情况利润为无穷小

也可以按照真实的循环过程来解题，如果设置了双循环在解题，则需要在循环的最前面
将basecase直接排除，这时候就相当于直接把i=0时的四个情况直接计算出来而不是交到循环中去
计算，所以这时候i=0且持有股票时的情况利润为计算出的-prices[i]
*/
    