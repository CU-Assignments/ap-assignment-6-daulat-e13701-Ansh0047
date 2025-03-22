class Solution {
    int brute(vector<int>&nums){
        //generate all subarrays
        int n = nums.size();
        int maxSum = INT_MIN;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                maxSum = max(maxSum,sum);
            }
        }

        return maxSum;
    }
public:
    int maxSubArray(vector<int>& nums) {
        // return brute(nums);
        // kadane algo
        int n = nums.size();
        int sum = 0, maxSum = INT_MIN;

        for(int i=0;i<n;i++){
            sum += nums[i];

            maxSum = max(maxSum,sum);
            if(sum < 0) sum = 0;
        }

        return maxSum;
    }
};