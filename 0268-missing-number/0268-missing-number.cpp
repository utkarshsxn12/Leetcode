class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actual = 0;
        int n = nums.size();
        int expected = n*(n+1)/2;
        for(int i=0;i<nums.size();i++){
            actual+=nums[i];

        }
        return expected-actual;
    }
};