class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 状态转移数组，dp(i) 表示到金额 = i 的时候所需的最小硬币数量
        vector<int> dp(amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            int minn = INT_MAX;
            for(int j = 0; j < coins.size(); ++j){
                if(i >= coins[j]){
                    minn = min(minn, dp[i - coins[j]]);
                }
            }
            if(minn == INT_MAX)dp[i] = INT_MAX;
            else dp[i] = minn + 1;
        }
        return dp[amount] == INT_MAX? -1: dp[amount];
    }
};
