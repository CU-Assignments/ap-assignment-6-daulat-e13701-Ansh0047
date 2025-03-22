class Solution {
    public:
        int rob(vector<int>& nums) {
            // dp[i] will be max loot by either robbing the house or not
            int n = nums.size();
            if(n==1) return nums[0];
            if(n==2) return max(nums[0],nums[1]); 
            vector<int>dp(n+1,0);
            dp[0] = nums[0];
    
            for(int i=1;i<n;i++){
                if(i-2 >= 0) dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
                else dp[i] = max(dp[i-1],nums[i]);
            }
    
            return dp[n-1];
        }
    };