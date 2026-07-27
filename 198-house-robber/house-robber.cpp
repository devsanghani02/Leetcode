class Solution {
public:
    int f(int i,vector<int>& nums,vector<int>& dp){
        if(i==0) return nums[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+f(i-2,nums,dp);
        int npick=f(i-1,nums,dp);
        return dp[i]=max(pick,npick);
    
    }
    int rob(vector<int>& nums) {
        
        
               vector<int> dp(nums.size(),-1);
               f(nums.size()-1,nums,dp);
            return f(nums.size()-1,nums,dp);
        
        
    }
};