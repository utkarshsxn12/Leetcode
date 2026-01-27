class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN, window_sum=0;
        for(int i=0; i<nums.size();i++){
            window_sum=max(window_sum+nums[i],nums[i]);
            max_sum=max(max_sum,window_sum);
        }
        return max_sum;
        
    }
};