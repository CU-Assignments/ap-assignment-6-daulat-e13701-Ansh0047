class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int>lis;
    
            for(int i=0;i<n;i++){
                if(lis.size() == 0 || nums[i] > lis.back()){
                    lis.push_back(nums[i]);
                }
                else{
                    // find the best position for the current number and that will be lower bound index
                    // bcoz lowerbound is nothing but the first number greater than or equal to x, so all the 
                    // numbers before it will be less than that for sure
                    int lbInd = lower_bound(begin(lis),end(lis),nums[i]) - lis.begin();
                    lis[lbInd] = nums[i];
                }
            }
    
            return lis.size();
        }
    };