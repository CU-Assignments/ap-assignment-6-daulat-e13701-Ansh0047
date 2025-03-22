class Solution {
    int solve(int ind, int buy, vector<int>&prices,vector<vector<int>>&dp){
        if(ind >= prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int maxProfit = 0;
        if(buy){
            int willBuy = -prices[ind] + solve(ind+1,0,prices,dp);
            int willNotBuy = 0 + solve(ind+1,1,prices,dp);
            maxProfit = max(willBuy, willNotBuy);
        }
        else{
            // for one day coldown we will jump to the next to next day
            int willSell = prices[ind] + solve(ind+2,1,prices,dp);
            int willNotSell = 0 + solve(ind+1,0,prices,dp);
            maxProfit = max(willSell, willNotSell);
        }

        return dp[ind][buy] = maxProfit;
    }
    int tabulation(vector<int>&prices){
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                // copy paste recursive code
                int maxProfit = 0;
                if(buy){
                    int willBuy = -prices[ind] + dp[ind+1][0];
                    int willNotBuy = 0 + dp[ind+1][1];

                    maxProfit = max(willBuy, willNotBuy);
                }
                else{
                    int willSell = prices[ind] + dp[ind+2][1];
                    int willNotSell = 0 + dp[ind+1][0];

                    maxProfit = max(willSell,willNotSell);
                }
                dp[ind][buy] = maxProfit;
            }
        }

        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return solve(0,1,prices,dp);

        return tabulation(prices);
    }
};