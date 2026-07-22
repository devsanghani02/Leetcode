class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int as;
        while(k>0){
            k--;
            if(k==0){
              as=pq.top();
            }
            pq.pop();
        }
        return as;
    }
};