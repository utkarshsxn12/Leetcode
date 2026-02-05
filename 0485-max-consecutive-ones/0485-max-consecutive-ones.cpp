class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int cnt=0;
        int maximum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                maximum=max(cnt,maximum);
            }
            else{
                cnt=0;
            }
        }
        return maximum;
    }
    };