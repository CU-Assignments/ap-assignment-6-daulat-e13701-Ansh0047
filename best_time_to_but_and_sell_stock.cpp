class Solution {
    public:
        int maxProfit(vector<int>& nums) {
            int n = nums.size();
            int minPrice = nums[0];
            int maxProfit = 0;
            for(int i=0;i<n;i++){
                maxProfit = max(maxProfit,nums[i] - minPrice);
                minPrice = min(minPrice,nums[i]);
            }
    
            return maxProfit;
        }
    };