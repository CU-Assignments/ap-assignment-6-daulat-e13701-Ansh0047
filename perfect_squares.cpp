class Solution {
    int solve(int n,vector<int>&dp){
        if(n <= 0) return 0;

        if(dp[n] != -1) return dp[n];

        int ans = n;
        for(int i=1;i*i<=n;i++){
            int square = i*i;
            ans = min(ans,1+solve(n-square,dp));
        }
        return dp[n] = ans;
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};