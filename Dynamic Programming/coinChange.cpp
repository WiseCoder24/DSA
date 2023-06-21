/*
322. Coin Change
Medium
16.4K
369
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/
class Solution {
public:
    int recursiveSolution(vector<int>& coins, int amount){
        if(amount < 0) return INT_MAX;// Because we have to find minimum number of coins
        if(amount == 0) return 0;
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = recursiveSolution(coins, amount-coins[i]);  
            if(ans!=INT_MAX)
                mini = min(mini,ans+1);
        }
        return mini;
    }
    int solutionUsingMem(vector<int>& coins, int amount,vector<int> &dp){
        if(amount < 0) return INT_MAX;// Because we have to find minimum number of coins
        if(amount == 0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solutionUsingMem(coins, amount-coins[i],dp);  
            if(ans!=INT_MAX)
                mini = min(mini,ans+1);
        }
        dp[amount] = mini;
        return dp[amount];
    }
    int solveUsingTab(vector<int> coins,int amount){
        vector<int> dp(amount+1,INT_MAX);
        // Base case
        dp[0] = 0;
        for(int target=1;target<=amount;target++){
            int mini = INT_MAX;
            for(int i=0;i<coins.size();i++){
                if(target-coins[i]>=0){
                    int ans = dp[target-coins[i]];  
                    if(ans!=INT_MAX)
                        mini = min(mini,ans+1);
                }
            }
            dp[target] = mini;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans = recursiveSolution(coins, amount);
        // if(ans==INT_MAX) return -1;
        // vector<int> dp(amount+1,-1);
        // int ans = solutionUsingMem(coins,amount,dp);
        int ans = solveUsingTab(coins,amount);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};