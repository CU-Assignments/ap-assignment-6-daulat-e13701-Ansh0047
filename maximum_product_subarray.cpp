class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            // brute genrate all subarrays
            // optimal find the max of prefix of suffix product
            // take care for zeros if it occurs new product starts
            // and incase of even -ves pro is +ve and for odd leave any 1 -ve
    
            int n = nums.size();
            int pre = 1,suff = 1;
            int maxPro = INT_MIN;
            for(int i=0;i<n;i++){
                pre *= nums[i];
                suff *= nums[n-i-1];
    
                maxPro = max({maxPro,suff,pre});
    
                if(pre == 0) pre = 1;
                if(suff == 0) suff = 1;
            }
    
            return maxPro;
        }
    };