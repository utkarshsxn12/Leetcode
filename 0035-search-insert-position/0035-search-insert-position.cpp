class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int mid, res;

        while(start<=end){
            mid = start+(end-start)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                end = mid-1;
            }
            else{
                start = mid+1;
                res=start;
            }
        }
        return res;

    }
};