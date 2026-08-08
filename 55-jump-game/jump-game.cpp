class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach= 0;
        if (n==1) return true;
        for(int i=0;i<n-1;i++){
            if (i>maxReach) return false;
            if (i+nums[i]>maxReach) maxReach=i+nums[i];
            if (maxReach>=n-1) return true;
        }
        return false;
    }
};