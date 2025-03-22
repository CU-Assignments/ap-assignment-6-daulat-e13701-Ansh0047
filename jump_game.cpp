class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            int jump = nums[0];
            if(n==1) return true;
            if(nums[0]==0) return false;
    
            for(int i=1;i<n-1;i++){
                if(i>=jump && nums[i]==0) return false;
                jump = max(jump,i+nums[i]);
            }
    
            return true;
        }
    };