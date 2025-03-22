class Solution {
    int dp[13][10001];
    int solve(vector<int>&arr, int n, int sum){
        if(sum == 0) return 0;
        if(n == 0 && sum != 0) return INT_MAX-1;

        if(dp[n][sum] != -1) return dp[n][sum];

        if(arr[n-1] <= sum){
            int taken = 1 + solve(arr,n,sum-arr[n-1]);
            int notTaken = solve(arr,n-1,sum);
            return dp[n][sum] = min(taken,notTaken);
        }
        else{
            return dp[n][sum] = solve(arr,n-1,sum);
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(coins,n,amount);

        return ans == INT_MAX-1 ? -1 : ans;
    }
};